#include <iostream>
#include <queue>
#include <stack>

using std::cin;
using std::cout;
using std::queue;
using std::stack;

int testCase , sizeStation , capacity , maxQueue , sizeQueue , total , it , result;
queue<int> station[101];
stack<int> ship;

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (cin >> testCase; testCase > 0; --testCase)
	{
		cin >> sizeStation >> capacity >> maxQueue;
		total = 0;
		result = 0;
		for (int i = 1; i <= sizeStation; ++i)
		{
			cin >> sizeQueue;
			total += sizeQueue;
			for (int j = 0; j < sizeQueue; ++j)
			{
				int t;
				cin >> t;
				station[i].push(t);
			}
		}
		it = 1;
		while (true)
		{
			while (!ship.empty())
			{
				if (station[it].size() == maxQueue)
				{
					while (ship.top() == it)
					{
						++result;
						ship.pop();
						if (total == 1)
							goto end_shipping;
						--total;
						if (ship.empty())
							break;
					}
					break;
				}
				int cargo = ship.top();
				ship.pop();
				++result;
				if (cargo == it)
				{
					if (total == 1)
						goto end_shipping;
					--total;
				}
				else
					station[it].push(cargo);
			}
			while (ship.size() < capacity &&
				   !station[it].empty())
			{
				ship.push(station[it].front());
				station[it].pop();
				++result;
			}
			it = it % sizeStation + 1;
			result += 2;
		}
	end_shipping:
		cout << result << '\n';
	}
	return 0;
}