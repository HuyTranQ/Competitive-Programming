#include <iostream>

using std::cin;
using std::cout;

int surplus , deficit;

int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> surplus)
	{
		cin >> deficit;
		int factor = 4;
		while (factor > 0)
		{
			if (factor * surplus < (5 - factor) * deficit)
				break;
			--factor;
		}
		int balance = 0;
		switch (factor)
		{
			case 4:
				balance = 10 * surplus - 2 * deficit;
				break;
			case 3:
				balance = 8 * surplus - 4 * deficit;
				break;
			case 2:
				balance = 6 * surplus - 6 * deficit;
				break;
			case 1:
				balance = 3 * surplus - 9 * deficit;
				break;
			case 0:
				balance = -12 * deficit;
				break;
			default:
				break;
		}
		if (balance < 0)
			cout << "Deficit";
		else
			cout << balance;
		cout << '\n';
	}
	return 0;
}