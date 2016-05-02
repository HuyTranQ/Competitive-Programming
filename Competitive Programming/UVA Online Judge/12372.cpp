#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int testSize , length , width , height;
	cin >> testSize;
	for (int i = 1; i <= testSize; ++i)
	{
		cin >> length >> width >> height;
		cout << "Case " << i << ": ";
		if (length > 20 || width > 20 || height > 20)
			cout << "bad";
		else
			cout << "good";
		cout << endl;
	}
	return 0;
}