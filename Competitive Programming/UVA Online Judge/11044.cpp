#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int testSize , n , m, remainN , remainM;
	cin >> testSize;
	int * result = new int[testSize];
	for (int i = 0; i < testSize; ++i)
	{
		cin >> n >> m;
		n -= 2;
		m -= 2;
		remainN = n % 3;
		remainM = m % 3;
		n = n / 3;
		m = m / 3;
		result[i] = n * m;
		if (remainN > 0)
			result[i] += m;
		if (remainM > 0)
			result[i] += n;
		if (remainN > 0 && remainM > 0)
			result[i] += 1;
	}
	for (int i = 0; i < testSize; ++i)
		cout << result[i] << endl;
	delete[] result;
	return 0;
}