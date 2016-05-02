#include <iostream>
#include <string>
#include <unordered_set>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::unordered_set;

string origin;
string result;
unordered_set<char> vowel = { 
	'a' , 'e' , 'u' , 'i' , 'o' , 'y' , 
	'A' , 'E' , 'U' , 'I' , 'O' , 'Y'
};

int main()
{
	std::ios::sync_with_stdio(false);
	result.reserve(200);
	getline(cin , origin);
	for (auto it = origin.cbegin() , endit = origin.cend(); it != endit; ++it)
		if (vowel.find(*it) == vowel.end())
		{
			result.push_back('.');
			if (*it < 97)
				result.push_back(*it + 32);
			else
				result.push_back(*it);
		}
	cout << result;
	return 0;
}