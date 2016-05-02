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
	list<string>::iterator it , itEnd;
	while (true)
	{
		getline(cin , line);
		int size = line.size();
		if (size == 0)
			break;
		int lastPosition = 0;
		result.resize(0);
		bool end = true;
		for (int i = 0; i < size; ++i)
			if (line[i] == '[')
			{
				if (end == true)
					result.push_back(line.substr(lastPosition , i - lastPosition));
				else
					result.push_front(line.substr(lastPosition , i - lastPosition));
				end = false;
				lastPosition = i + 1;
			}
			else if (line[i] == ']')
			{
				if (end == true)
					result.push_back(line.substr(lastPosition , i - lastPosition));
				else
					result.push_front(line.substr(lastPosition , i - lastPosition));
				end = true;
				lastPosition = i + 1;
			}
		if (lastPosition != size)
		{
			if (end == true)
				result.push_back(line.substr(lastPosition));
			else
				result.push_front(line.substr(lastPosition));
		}
		itEnd = result.end();
		for (it = result.begin(); it != itEnd; ++it)
			cout << (* it);
		cout << endl;
	}
	return 0;
}