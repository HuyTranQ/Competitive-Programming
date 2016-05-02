#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int testSize , n;
	cin >> testSize;
	while (testSize > 0)
	{
		--testSize;
		cin >> n;
		n = 315 * n + 36962;
		if (n < 0)
			n = -n;
		cout << ((n / 10) % 10) << endl;
	}
	return 0;
}