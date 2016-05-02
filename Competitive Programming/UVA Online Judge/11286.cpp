#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::sort;
using std::vector;

struct Frequency
{
	int frequency;
	Frequency() : frequency(0)
	{}
};

int sizeFrosh;
vector<int> frosh(5);
map<vector<int> , Frequency> data;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> sizeFrosh &&
		   sizeFrosh > 0)
	{
		for (int i = 0; i < sizeFrosh; ++i)
		{
			cin >> frosh[0];
			for (int j = 1; j < 5; ++j)
			{
				int t;
				cin >> t;
				int k;
				for (k = j; k > 0; --k)
					if (frosh[k - 1] <= t)
						break;
					else
						frosh[k] = frosh[k - 1];
				frosh[k] = t;
			}
			++data[frosh].frequency;
		}
		map<vector<int> , Frequency>::iterator it = data.begin() , end = data.end();
		int result = 0;
		int max = -1;
		while (it != end)
		{
			if (it->second.frequency > max)
			{
				max = it->second.frequency;
				result = max;
			}
			else if (it->second.frequency == max)
				result += max;
			++it;
		}
		cout << result << '\n';
		data.clear();
	}
	return 0;
}