#include <iostream>

using std::cin;
using std::cout;

unsigned number , a;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> number)
	{
		if (number == 0)
			break;
		a = 0;
		int counter = 0;
		for (unsigned i = 1; i != 0; i <<= 1)
		{
			if (0 != (i & number))
			{
				++counter;
				if (counter % 2 == 1)
					a |= i;
			}
		}
		cout << a << ' ' << (number - a) << '\n';
	}
	return 0;
}