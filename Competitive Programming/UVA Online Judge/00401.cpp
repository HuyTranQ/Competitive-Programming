#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

//				"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
string mirror = " 1SE Z  8 A   3  HIL JM O   2TUVWXY5";
string result[4] = {
	" -- is not a palindrome.",
	" -- is a regular palindrome." ,
	" -- is a mirrored string." ,
	" -- is a mirrored palindrome."
};
string line;

int isPalindrome(string const & text);
int isMirrored(string const & text);
char mirrorOf(char input);

int main()
{
	while (true)
	{
		getline(cin , line);
		if (line.length() == 0)
			break;
		cout << line << result[isPalindrome(line) + isMirrored(line)] << endl << endl;
	}
	return 0;
}

int isPalindrome(string const & text)
{
	int length = text.length();
	int midLength = (length / 2);
	--length;
	for (int i = 0; i < midLength; ++i)
		if (text[i] != text[length - i])
			return 0;
	return 1;
}

int isMirrored(string const & text)
{
	int length = text.length();
	int midLength = (length / 2) + (length % 2);
	--length;
	for (int i = 0; i < midLength; ++i)
		if (text[i] >= 'a' ||
			text[i] != mirrorOf(text[length - i]))
			return 0;
	return 2;
}

char mirrorOf(char input)
{
	if (input >= 'A')
		return mirror[10 + input - 'A'];
	else
		return mirror[input - '0'];
}