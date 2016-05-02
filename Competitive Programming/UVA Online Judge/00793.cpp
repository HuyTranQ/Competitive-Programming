#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::vector;

struct Element
{
	int parent , rank;
	Element()
	{}
	Element(int parent , int rank) : parent(parent) , rank(rank)
	{}
	int getParent(vector<Element> const & data) const;
};

int testCase;
string line;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> testCase;
	cin.ignore();
	string line;
	for (getline(cin , line); testCase > 0; --testCase)
	{
		int sizeComputer;
		cin >> sizeComputer;
		cin.ignore();
		int success = 0 , failure = 0;
		vector<Element> unionSet;
		unionSet.push_back(Element());
		for (int i = 1; i <= sizeComputer; ++i)
			unionSet.push_back(Element(i , 1));
		while (getline(cin , line) &&
			   !line.empty())
		{
			int index = 2;
			int a = 0 , b = 0;
			while (line[index] != ' ')
			{
				a = a * 10 + line[index] - '0';
				++index;
			}
			int length = line.length();
			++index;
			while (index < length)
			{
				b = b * 10 + line[index] - '0';
				++index;
			}
			int parentA = unionSet[a].getParent(unionSet);
			int parentB = unionSet[b].getParent(unionSet);
			if (line[0] == 'q')
			{
				if (parentA != parentB)
					++failure;
				else
					++success;
			}
			else if (unionSet[parentA].rank < unionSet[parentB].rank)
				unionSet[parentA].parent = parentB;
			else
			{
				unionSet[parentB].parent = parentA;
				if (a != b &&
					unionSet[parentA].rank == unionSet[parentB].rank)
					++unionSet[parentA].rank;
			}
		}
		cout << success << ',' << failure << '\n';
		if (testCase > 1)
			cout << '\n';
	}
	return 0;
}

int Element::getParent(vector<Element> const & data) const
{
	int result = parent;
	while (result != data[result].parent)
		result = data[result].parent;
	return result;
}