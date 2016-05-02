#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int isPalindrome(string const & text);
bool isAlpha(char input);

int main()
{
	string line;
	string result[2] = 
	{
		"Uh oh..",
		"You won't be eaten!"
	};
	while (true)
	{
		getline(cin , line);
		if (line == "DONE")
			break;
		cout << result[isPalindrome(line)] << endl;
	}
	return 0;
}

int isPalindrome(string const & text)
{
	int length = text.length();
	int i = 0 , j = length - 1;
	while (i < j)
	{
		while (i < length && !isAlpha(text[i]))
			++i;
		while (j >= 0 && !isAlpha(text[j]))
			--j;
		if (tolower(text[i]) != tolower(text[j]))
			return 0;
		else
		{
			++i;
			--j;
		}
	}
	return 1;
}

bool isAlpha(char input)
{
	return !(input == ' ' || input == '.' || input == ',' || 
			 input == '!' || input == '?');
}