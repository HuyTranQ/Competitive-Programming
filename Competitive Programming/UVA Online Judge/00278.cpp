#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int m , n;
	char piece;
	int inputSize;
	cin >> inputSize;
	while (inputSize > 0)
	{
		cin >> piece >> m >> n;
		switch (piece)
		{
			case 'r':
				cout << ((m < n) ? m : n);
				break;
			case 'k':
				m *= n;
				cout << (m / 2 + m % 2);
				break;
			case 'Q':
				cout << ((m < n) ? m : n);
				break;
			case 'K':
				cout << (m / 2 + m % 2) * (n / 2 + n % 2);
				break;
			default:
				break;
		}
		cout << endl;
		--inputSize;
	}
	return 0;
}