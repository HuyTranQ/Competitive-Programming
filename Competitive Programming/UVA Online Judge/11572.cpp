#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::unordered_map;

struct Index
{
	int index;
	Index() : index(-1)
	{}
};

int testCase , sizeSnow , snowFlake;
unordered_map<int , Index> data;

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (cin >> testCase; testCase > 0; --testCase)
	{
		cin >> sizeSnow;
		int result = 0;
		int begin = 0;
		for (int i = 0; i < sizeSnow; ++i)
		{
			cin >> snowFlake;
			int index = data[snowFlake].index;
			if (index != -1)
			{
				int t = i - begin;
				if (t > result)
					result = t;
				if (index >= begin)
					begin = index + 1;
			}
			data[snowFlake].index = i;
		}
		int t = sizeSnow - begin;
		if (t > result)
			result = t;
		cout << result << '\n';
		data.clear();
	}
	return 0;
}