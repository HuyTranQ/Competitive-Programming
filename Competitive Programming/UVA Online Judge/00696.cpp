#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int m , n;
	while (true)
	{
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		if (m == 0 ||
			n == 0)
			cout << 0;
		else if (m == 1 ||
				 n == 1)
			cout << (m + n - 1);
		else if (m == 2)
		{
			int a = n % 4;
			a = (a == 3) ? 2 : a;
			cout << (n / 4) * 4 + a * 2;
		}
		else if (n == 2)
		{
			int a = m % 4;
			a = (a == 3) ? 2 : a;
			cout << (m / 4) * 4 + a * 2;
		}
		else
		{
			int product = m * n;
			cout << (product / 2 + product % 2);
		}
		cout << " knights may be placed on a " << m << " row " << n << " column board." << endl;
	}
	return 0;
}