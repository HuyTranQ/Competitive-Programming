#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	long long sum , dif , a , b , number;
	cin >> number;
	for (int i = 0; i < number; ++i)
	{
		cin >> sum >> dif;
		if (sum > dif)
		{
			a = (sum + dif) / 2;
			b = (sum - dif) / 2;
		}
		else
		{
			a = (sum - dif) / 2;
			b = (sum + dif) / 2;
		}
		if (a + b != sum || a - b != dif)
		{
			a = -a;
			b = -b;
			if (a + b != sum || a - b != dif)
				cout << "impossible";
			else if (a < b)
				cout << b << ' ' << a;
			else
				cout << a << ' ' << b;
		}
		else if (a < b)
			cout << b << ' ' << a;
		else
			cout << a << ' ' << b;
		cout << endl;
	}
	return 0;
}