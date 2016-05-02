#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::unordered_set;
using std::sort;
using std::vector;

struct Contestant
{
	bool hasSubmitted;
	int correct;
	int penalty;
	int incorrect[11];
};

Contestant contestant[101];
vector<int> listSubmitted;
unordered_set<int> problem[11];
string line;
int testCase , length , index;
int input[3];

bool compareContestant(int const & a ,
					   int const & b);

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> testCase;
	cin.ignore();
	for (int i = 1; i <= 100; ++i)
	{
		contestant[i].hasSubmitted = false;
		contestant[i].correct = 0;
		contestant[i].penalty = 0;
		for (int j = 1; j <= 10; ++j)
			contestant[i].incorrect[j] = 0;
	}
	for (getline(cin , line); ; --testCase)
	{
		listSubmitted.clear();
		for (int i = 1; i <= 10; ++i)
			problem[i].clear();
		while (getline(cin , line))
		{
			if (line.empty())
				break;
			for (int i = 0, index = 0; i < 3; ++i , ++index)
			{
				input[i] = 0;
				do
				{
					input[i] = input[i] * 10 + line[index] - '0';
					++index;
				} while (line[index] != ' ');
			}
			if (!contestant[input[0]].hasSubmitted)
			{
				contestant[input[0]].hasSubmitted = true;
				listSubmitted.push_back(input[0]);
			}
			index = line.length() - 1;
			if (line[index] == 'R' ||
				line[index] == 'U' ||
				line[index] == 'E')
				continue;
			if (problem[input[1]].find(input[0]) != problem[input[1]].end())
				continue;
			if (line[index] == 'C')
			{
				problem[input[1]].insert(input[0]);
				++contestant[input[0]].correct;
				contestant[input[0]].penalty += input[2] + 20 * contestant[input[0]].incorrect[input[1]];
			}
			else
				++contestant[input[0]].incorrect[input[1]];
		}
		sort(listSubmitted.begin() , listSubmitted.end() , compareContestant);
		length = listSubmitted.size();
		for (index = 0; index < length; ++index)
		{
			cout << listSubmitted[index] << ' ' << contestant[listSubmitted[index]].correct << ' ' << contestant[listSubmitted[index]].penalty << '\n';
			contestant[listSubmitted[index]].correct = 0;
			contestant[listSubmitted[index]].penalty = 0;
			contestant[listSubmitted[index]].hasSubmitted = false;
			for (int j = 1; j <= 10; ++j)
				contestant[listSubmitted[index]].incorrect[j] = 0;
		}
		if (testCase == 1)
			break;
		cout << '\n';
		listSubmitted.clear();
	}
	return 0;
}

bool compareContestant(int const & a ,
					   int const & b)
{
	Contestant &x = contestant[a] , &y = contestant[b];
	if (x.correct > y.correct)
		return true;
	else if (x.correct < y.correct)
		return false;
	else if (x.penalty < y.penalty)
		return true;
	else if (x.penalty > y.penalty)
		return false;
	else
		return a < b;
}