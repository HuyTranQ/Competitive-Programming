#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int degree[4];
	int result , dif;
	while (true)
	{
		cin >> degree[0] >> degree[1] >> degree[2] >> degree[3];
		if (degree[0] + degree[1] + degree[2] + degree[3] == 0)
			break;
		result = 0;
		dif = degree[0] - degree[1];
		if (dif < 0)
			dif = 40 + dif;
		result += dif;
		dif = degree[2] - degree[1];
		if (dif < 0)
			dif = 40 + dif;
		result += dif;
		dif = degree[2] - degree[3];
		if (dif < 0)
			dif = 40 + dif;
		result += dif;
		cout << (result * 9 + 1080) << endl;
	}
	return 0;
}