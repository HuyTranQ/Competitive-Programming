#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int testCase , payChar , lineTotal , length , result;
char paid;
int payment[128];
string line;

int main()
{
	for (cin >> testCase; testCase > 0; --testCase)
	{
		result = 0;
		for (int i = 33; i < 127; ++i)
			payment[i] = 0;
		for (cin >> payChar; payChar > 0; --payChar)
		{
			cin >> paid;
			cin >> payment[paid];
		}
			
		for (cin >> lineTotal , cin.ignore(); lineTotal > 0; --lineTotal)
		{
			getline(cin , line);
			for (length = line.length() - 1; length >= 0; --length)
				if (32 < line[length] && line[length] < 128)
					result += payment[line[length]];
		}
		cout << result / 100 << '.';
		int t = result % 100;
		if (t < 10)
			cout << 0;
		cout << t << "$\n";
	}
	return 0;
}