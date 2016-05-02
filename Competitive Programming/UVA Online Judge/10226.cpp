#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::map;

struct Frequency
{
	int frequency;
	Frequency() : frequency(0)
	{}
};

int testCase;
string tree;
map<string , Frequency> data;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> testCase;
	cout.precision(4);
	cin.ignore();
	for (cin.ignore(); ; --testCase)
	{
		int size = 0;
		while (getline(cin , tree) &&
			   !tree.empty())
		{
			++size;
			++data[tree].frequency;
		}
		map<string , Frequency>::iterator it = data.begin() , end = data.end();
		while (it != end)
		{
			cout << it->first << ' ' << std::fixed << 100 * (it->second.frequency / (double) size) << '\n';
			++it;
		}
		if (testCase == 1)
			break;
		cout << '\n';
		data.clear();
	}
	return 0;
}