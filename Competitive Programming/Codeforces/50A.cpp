#include <iostream>

using std::cin;
using std::cout;

int width , height;

int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , c , d;
	cin >> width >> height;
	cout << ((width * height) / 2);
	return 0;
}