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
	int testSize;
	cin >> testSize;
	getline(cin , line);
	while (testSize > 0)
	{
		--testSize;
		getline(cin , line);
		int length = line.size();
		if (length == 1 && (line[0] == '1' || line[0] == '4') ||
			length == 2 && line[0] == '7' && line[1] == '8')
			cout << '+' << endl;
		else if (length >= 2)
			if (line[length - 1] == '5' &&
				line[length - 2] == '3')
				cout << '-' << endl;
			else if (line[0] == '9' &&
					 line[length - 1] == '4')
					 cout << '*' << endl;
			else if (length >= 3 &&
					 line[0] == '1' &&
					 line[1] == '9' &&
					 line[2] == '0')
					 cout << '?' << endl;
	}
	return 0;
}