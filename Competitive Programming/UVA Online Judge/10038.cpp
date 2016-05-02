#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int n , pre , cur , dif , sum;
vector<int> check;

int main()
{
	while (cin >> n)
	{
		cin >> pre;
		check.clear();
		check.resize(n , 0);
		sum = n - 1;
		int i = 1;
		for (; i < n; ++i)
		{
			cin >> cur;
			dif = pre - cur;
			if (dif < 0)
				dif = -dif;
			if (dif > 0 && dif < n)
			{
				if (check[dif] == 0)
					--sum;
				else if (check[dif] == 2)
				{
					for (++i; i < n; ++i)
						cin >> cur;
					break;
				}
				++check[dif];
			}
			pre = cur;
		}
		cout << ((sum == 0) ? "Jolly" : "Not jolly") << endl;
	}
	return 0;
}