#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

int sizeNumber;
priority_queue<long long , vector<long long>, std::greater<long long>> number;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> sizeNumber &&
		   sizeNumber > 0)
	{
		for (int i = 0; i < sizeNumber; ++i)
		{
			int t;
			cin >> t;
			number.push(t);
		}
		long long result = 0;
		while (true)
		{
			long long first = number.top();
			number.pop();
			if (number.empty())
				break;
			else
			{
				first += number.top();
				result += first;
				number.pop();
				number.push(first);
			}
		};
		cout << result << '\n';
	}
	return 0;
}