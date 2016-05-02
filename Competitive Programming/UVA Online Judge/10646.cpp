#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string line;
	int sizeTest;
	int x , y;
	int maxSize = 156;
	int gapBegin;
	char c;
	cin >> sizeTest;
	cin.ignore();
	for (int i = 1; i <= sizeTest; ++i)
	{
		getline(cin , line);
		int begin = 78;
		y = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (begin < 0)
				break;
			c = line[begin];
			if (c >= '2' &&
				c <= '9')
				x = c - 48;
			else
				x = 10;
			begin -= (11 - x) * 3;
			y += x;
		}
		y *= 3;
		gapBegin = y - begin;
		if (gapBegin > 0)
			y = 75 + gapBegin;
		cout << "Case " << i << ": " << line[y] << line[y + 1] << endl;
	}
	
	return 0;
}