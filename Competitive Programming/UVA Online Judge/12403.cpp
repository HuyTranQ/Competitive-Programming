#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::string;
using std::getline;

int main()
{
	int transactionSize;
	int account = 0;
	string line;
	cin >> transactionSize;
	getline(cin , line);
	while (transactionSize > 0)
	{
		--transactionSize;
		getline(cin , line);
		if (line == "report")
			cout << account << endl;
		else
			account += stoi(line.substr(line.find_first_of(' ')));
	}
	return 0;
}