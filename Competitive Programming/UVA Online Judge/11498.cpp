#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int nCoord , divX , divY , coordX , coordY;
	string result = "  ";
	while (true)
	{
		cin >> nCoord;
		if (nCoord == 0)
			break;
		cin >> divX >> divY;
		while (nCoord > 0)
		{
			--nCoord;
			cin >> coordX >> coordY;
			if (coordX == divX ||
				coordY == divY)
			{
				cout << "divisa" << endl;
				continue;
			}
			result[0] = (coordY > divY) ? 'N' : 'S';
			result[1] = (coordX > divX) ? 'E' : 'O';
			cout << result << endl;
		}
	}
	return 0;
}