#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;

int word_size;
string word;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> word_size;
	cin.ignore();
	for (; word_size > 0; --word_size)
	{
		getline(cin , word);
		if (word.length() <= 10)
		{
			cout << word << '\n';
			continue;
		}
		cout << word.front() << (word.length() - 2) << word.back() << '\n';
	}
	return 0;
}