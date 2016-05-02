#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	int testSize;
	string one = "one";
	string word;
	cin >> testSize;
	getline(cin , word);
	while (testSize > 0)
	{
		--testSize;
		getline(cin , word);
		if (word.length() == 5)
			cout << 3;
		else
		{
			int counter = 0;
			for (int i = 0; i < 3; ++i)
				if (word[i] != one[i])
					++counter;
			cout << ((counter <= 1) ? 1 : 2);
		}
		cout << endl;
	}
	return 0;
}