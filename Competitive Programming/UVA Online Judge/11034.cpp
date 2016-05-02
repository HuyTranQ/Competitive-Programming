#include <iostream>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::string;
using std::queue;

int testCase , ferryLength , sizeCar;
int riverBank[] = { 'l' , 'r' };
queue<int> bank[2];

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (cin >> testCase; testCase > 0; --testCase)
	{
		cin >> ferryLength >> sizeCar;
		ferryLength *= 100;
		for (int i = 0; i < sizeCar; ++i)
		{
			int carLength;
			string t;
			cin >> carLength >> t;
			bank[((t[0] == 'l') ? 0 : 1)].push(carLength);
		}
		int result = 0;
		int capacity;
		int side = 0;
		while (!bank[0].empty() ||
			   !bank[1].empty())
		{
			capacity = 0;
			while (!bank[side].empty())
			{
				int length = bank[side].front();
				if (length + capacity > ferryLength)
					break;
				capacity += length;
				bank[side].pop();
			}
			++result;
			side = (side + 1) % 2;
		}
		cout << result << '\n';
	}
	return 0;
}