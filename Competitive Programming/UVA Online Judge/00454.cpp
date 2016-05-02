#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::sort;
using std::remove;
using std::vector;

int testSize , size;
vector<string> listWord;
vector<string> listAnagram;

int main()
{
	string line;
	cin >> testSize;
	cin.ignore();
	getline(cin , line);
	while (testSize > 0)
	{
		listWord.clear();
		listAnagram.clear();
		while (true)
		{
			getline(cin , line);
			if (line.empty())
				break;
			listWord.push_back(line);
		}
		sort(listWord.begin() , listWord.end());
		size = listWord.size();
		for (int i = 0; i < size; ++i)
		{
			line = listWord[i];
			line.erase(remove(line.begin() , line.end() , ' ') , line.end());
			sort(line.begin() , line.end());
			listAnagram.push_back(line);
		}
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (listAnagram[i] == listAnagram[j])
					cout << listWord[i] << " = " << listWord[j] << endl;
		if (testSize > 1)
			cout << endl;
		--testSize;
	}
	return 0;
}