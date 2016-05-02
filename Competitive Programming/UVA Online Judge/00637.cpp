#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int pageNumber , sheetNumber , blankNumber;
	char * fold[2] = { "front:" , "back :" };
	while (true)
	{
		cin >> pageNumber;
		if (pageNumber == 0)
			break;
		cout << "Printing order for " << pageNumber << " pages:" << endl;
		if (pageNumber == 1)
		{
			cout << "Sheet 1, front: Blank, 1" << endl;
			continue;
		}
		sheetNumber = pageNumber / 4 + (pageNumber % 4 != 0);
		blankNumber = sheetNumber * 4 - pageNumber;
		for (int i = 1; i <= sheetNumber; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				cout << "Sheet " << i << ", " << fold[j] << ' ';
				if (j == 0)
				{
					if (blankNumber > 0)
					{
						cout << "Blank";
						--blankNumber;
					}
					else
						cout << (2 * sheetNumber - i + 1) * 2;
					cout << ", " << 2 * i - 1 << endl;;
				}
				else
				{
					cout << 2 * i << ", ";
					if (blankNumber > 0)
					{
						cout << "Blank";
						--blankNumber;
					}
					else
						cout << (2 * sheetNumber - i + 1) * 2 - 1;
					cout << endl;
				}
			}
		}
			
	}
	return 0;
}