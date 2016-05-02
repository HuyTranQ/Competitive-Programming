#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::getline;

int main()
{
	string line;
	list<string> result;
	while (getline(cin , line))
		result.push_back(line);
	list<string>::iterator it , end = result.end();
	for (it = result.begin(); it != end; ++it)
		cout << (*it) << endl;
	return 0;
}