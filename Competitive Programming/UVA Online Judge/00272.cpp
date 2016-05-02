
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;

int main()
{
	string line;
	bool open = true;
	int parenPosition , maxLength , lastPosition;
	list<string> result;
	while (getline(cin , line))
	{
		maxLength = line.size();
		if (maxLength == 0)
			break;
		lastPosition = 0;
		for (int i = 0; i < maxLength; ++i)
			if (line[i] == '"')
			{
				result.push_back(line.substr(lastPosition , i - lastPosition));
				result.push_back((open) ? "``" : "''");
				lastPosition = i + 1;
				open = !open;
			}
		result.push_back(line.substr(lastPosition));
		result.push_back("\n");
	}

	list<string>::iterator it , end = result.end();
	for (it = result.begin(); it != end; ++it)
		cout << (*it);
	return 0;
}
