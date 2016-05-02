#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sizeInput , sizeStudent;
	cin >> sizeInput;
	int number , min;
	for (int i = 1; i <= sizeInput; ++i)
	{
		cin >> sizeStudent;
		min = 0;
		while (sizeStudent > 0)
		{
			cin >> number;
			if (number > min)
				min = number;
			--sizeStudent;
		}
		cout << "Case " << i << ": " << min << endl;
	}
	return 0;
}