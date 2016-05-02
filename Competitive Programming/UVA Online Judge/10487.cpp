#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

int sizeNumber;

int main()
{
	std::ios::sync_with_stdio(false);
	int counter = 1;
	while (cin >> sizeNumber &&
		   sizeNumber > 0)
	{
		vector<int> input(sizeNumber);
		for (int i = 0; i < sizeNumber; ++i)
			cin >> input[i];
		sort(input.begin() , input.end());
		int sizeQuery;
		cin >> sizeQuery;
		cout << "Case " << counter << ":\n";
		++counter;
		for (int i = 0; i < sizeQuery; ++i)
		{
			int sum;
			cin >> sum;
			int u = 0;
			int v = sizeNumber - 1;
			int result = input[u] + input[v];
			int nearSum = result;
			if (result != sum)
			{
				while (true)
				{
					if (nearSum < sum)
						++u;
					else
						--v;
					if (u >= v)
						break;
					nearSum = input[u] + input[v];
					if (nearSum == sum)
					{
						result = nearSum;
						break;
					}
					int newDiff = sum - nearSum;
					int oldDiff = sum - result;
					if (newDiff < 0)
						newDiff = -newDiff;
					if (oldDiff < 0)
						oldDiff = -oldDiff;
					if (newDiff <= oldDiff)
						result = nearSum;
				}
			}
			cout << "Closest sum to " << sum << " is " << result << ".\n";
		}
	}
	return 0;
}