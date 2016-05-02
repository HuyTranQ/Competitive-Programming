#include <iostream>
#include <string>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::queue;
using std::vector;
using std::string;

int testCase , sizeFerry , timeTransition , sizeCar , side , timeCounter;
vector<int> arrival;
queue<int> bank[2];
string riverSide;

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (cin >> testCase; ; --testCase)
	{
		cin >> sizeFerry >> timeTransition >> sizeCar;
		arrival.resize(sizeCar);
		for (int i = 0; i < sizeCar; ++i)
		{
			cin >> arrival[i] >> riverSide;
			bank[((riverSide[0] == 'r') ? 1 : 0)].push(i);
		}
		side = 0;
		timeCounter = 0;
		while (!bank[0].empty() ||
			   !bank[1].empty())
		{
			int next = timeCounter + timeTransition;
			if (!bank[side].empty())
			{
				int front = bank[side].front();
				if (arrival[front] > timeCounter)
				{
					int t = arrival[front];
					int otherSide = (side + 1) % 2;
					if (!bank[otherSide].empty())
					{
						int otherFront = bank[otherSide].front();
						if (arrival[otherFront] < arrival[front])
						{
							side = otherSide;
							if (timeCounter < arrival[otherFront])
								timeCounter = arrival[otherFront] + timeTransition;
							else
								timeCounter += timeTransition;
							continue;
						}
					}
					timeCounter = arrival[front];
					continue;
				}
				else
				{
					int capacity = 0;
					do
					{
						arrival[front] = next;
						bank[side].pop();
						++capacity;
						if (bank[side].empty() ||
							capacity == sizeFerry)
							break;
						front = bank[side].front();
					} while (arrival[front] <= timeCounter);
				}
			}
			else
			{
				side = (side + 1) % 2;
				int front = bank[side].front();
				if (timeCounter < arrival[front])
					timeCounter = arrival[front] + timeTransition;
				else
					timeCounter += timeTransition;
				continue;
			}
			timeCounter = next;
			side = (side + 1) % 2;
		}
		for (int i = 0; i < sizeCar; ++i)
			cout << arrival[i] << '\n';
		if (testCase == 1)
			break;
		cout << '\n';
	}
	return 0;
}