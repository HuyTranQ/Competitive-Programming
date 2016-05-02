#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int sizeJack , sizeJill;
vector<int> jackCD;

int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> sizeJack >> sizeJill && sizeJack > 0 && sizeJill > 0)
	{
		jackCD.resize(sizeJack);
		int jack = 0;
		int result = 0;
		for (int i = 0; i < sizeJack; ++i)
			cin >> jackCD[i];
		for (int i = 0; i < sizeJill; ++i)
		{
			int jillCD;
			cin >> jillCD;
			if (jack == sizeJack)
			{
				while (true)
				{
					++i;
					if (i == sizeJill)
						break;
					cin >> jillCD;
				}
				break;
			}
			do
			{
				if (jackCD[jack] == jillCD)
				{
					++jack;
					++result;
					break;
				}
				if (jackCD[jack] > jillCD)
					break;
				++jack;
			} while (jack < sizeJack);
		}
		cout << result << '\n';
	}
	return 0;
}