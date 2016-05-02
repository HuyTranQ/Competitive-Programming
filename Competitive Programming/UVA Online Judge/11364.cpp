#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int testSize;
	cin >> testSize;

	int nPosition , min, max, position;
	while (testSize > 0)
	{
		cin >> nPosition;
		min = 100;
		max = -1;
		while (nPosition > 0)
		{
			cin >> position;
			if (position < min)
				min = position;
			if (position > max)
				max = position;
			--nPosition;
		}
		cout << (max - min) * 2 << endl;
		--testSize;
	}
	return 0;
}