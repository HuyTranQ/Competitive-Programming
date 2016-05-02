#include <iostream>
#include <vector>
#include <set>
#include <functional>

using std::cin;
using std::cout;
using std::vector;
using std::multiset;

int testCase , sizeBattle;
int sizeArmy[2];
vector<int> remain[2];
multiset<int , std::greater<int>> army[2];
char * result[] =
{
	"",
	"blue wins\n",
	"green wins\n",
	"green and blue died\n"
};

int main()
{
	std::ios::sync_with_stdio(false);
	for (cin >> testCase; ; --testCase)
	{
		cin >> sizeBattle >> sizeArmy[0] >> sizeArmy[1];
		for (int i = 0; i < 2; ++i)
		{
			int size = sizeArmy[i];
			while (size > 0)
			{
				int t;
				cin >> t;
				army[i].insert(t);
				--size;
			}
		}
		remain[0].reserve(sizeBattle);
		remain[1].reserve(sizeBattle);
		multiset<int , std::greater<int>>::iterator it[2];
		int signal = 0;
		do
		{
			for (int i = 0; i < sizeBattle; ++i)
			{
				it[0] = army[0].begin();
				it[1] = army[1].begin();
				int green = (*it[0]) , blue = (*it[1]);
				if (green > blue)
					remain[0].push_back(green - blue);
				else if (green < blue)
					remain[1].push_back(blue - green);
				army[0].erase(it[0]);
				army[1].erase(it[1]);
				if (army[0].empty() ||
					army[1].empty())
					break;
			}
			for (int i = 0; i < 2; ++i)
			{
				int size = remain[i].size();
				for (int j = 0; j < size; ++j)
					army[i].insert(remain[i][j]);
				remain[i].clear();
			}
			if (army[0].empty())
				signal += 1;
			if (army[1].empty())
				signal += 2;
		} while (signal == 0);
		cout << result[signal];
		if (signal < 3)
		{
			signal %= 2;
			multiset<int , std::greater<int>>::iterator survivor = army[signal].begin() , end = army[signal].end();
			while (survivor != end)
			{
				cout << (*survivor) << '\n';
				++survivor;
			}
		}
		if (testCase == 1)
			break;
		cout << '\n';
		army[0].clear();
		army[1].clear();
	}
	return 0;
}