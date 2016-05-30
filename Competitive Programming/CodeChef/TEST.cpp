#include <iostream>

using std::cin;
using std::cout;

int main()
{
	std::ios::sync_with_stdio(false);
	int number;
	while (cin >> number && number != 42)
		cout << number << '\n';
	return 0;
}