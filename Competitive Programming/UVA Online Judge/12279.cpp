#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int treatSize , element , supposed, real;
	for (int i = 1; true; ++i)
	{
		cin >> treatSize;
		if (treatSize == 0)
			break;
		supposed = 0;
		real = 0;
		for (int j = 0; j < treatSize; ++j)
		{
			cin >> element;
			if (element == 0)
				++supposed;
			else
				++real;
		}
		cout << "Case " << i << ": " << (real - supposed) << endl;
	}
	return 0;
}