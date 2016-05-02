#include <iostream>

using std::cin;
using std::cout;

unsigned long long width , height , size;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> width >> height >> size;
	unsigned long long a = width / size;
	unsigned long long b = height / size;
	unsigned long long c = width % size;
	unsigned long long d = height % size;
	unsigned long long result = a * b;
	if (c > 0)
		result += b;
	if (d > 0)
		result += a;
	if (c > 0 && d > 0)
		++result;
	cout << result;
	return 0;
}