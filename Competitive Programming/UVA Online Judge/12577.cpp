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
	int counter = 1;
	while (true)
	{
		getline(cin , line);
		if (line == "*")
			break;
		cout << "Case " << counter << ": Hajj-e-" << ((line[0] == 'U') ? "Asghar" : "Akbar") << endl;
		++counter;
	}
	return 0;
}