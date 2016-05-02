#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	int length , sizeBreak;
	string line , result;
	while (true)
	{
		cin >> length;
		cin.ignore();
		if (length == 0)
			break;
		getline(cin , line);
		sizeBreak = line.size();
		result = "+x";
		for (int i = 1; i < sizeBreak; i += 3)
		{
			if (line[i] == 'o')
				continue;
			if (result[1] == 'x')
			{
				result[1] = line[i];
				result[0] = (result[0] == line[i - 1]) ? '+' : '-';
			}
			else if (result[1] == line[i])
			{
				result[1] = 'x';
				result[0] = (result[0] == line[i - 1]) ? '-' : '+';
			}
		}
		cout << result << endl;
	}
	return 0;
}