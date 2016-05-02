#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

int main()
{
	string language[] = { "HELLO" , "HOLA" , "HALLO" , "BONJOUR" , "CIAO" , "ZDRAVSTVUJTE" };
	string country[] = { "ENGLISH" , "SPANISH" , "GERMAN" , "FRENCH" , "ITALIAN" , "RUSSIAN" };
	vector<int> result;
	string unknown = "UNKNOWN";
	string line;
	for (int i = 1; true; ++i)
	{
		getline(cin , line);
		if (line == "#")
			break;
		int j;
		for (j = 0; j < 6; ++j)
			if (line == language[j])
				break;
		result.push_back(j);
	}
	int size = result.size();
	for (int i = 0; i < size; ++i)
		cout << "Case " << (i + 1) << ": " << ((result[i] == 6) ? unknown : country[result[i]]) << endl;
		
	return 0;
}