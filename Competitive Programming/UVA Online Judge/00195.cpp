#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

//	iostream
using std::cin;
using std::cout;
using std::endl;
//	algorithm
using std::sort;
using std::swap;
//	string
using std::string;
using std::getline;
//	vector
using std::vector;

bool nextPermutation(string & text);
int compareCharacter(char a , char b);
bool comparator(char const & a ,
				char const & b);

int main()
{
	string line;
	int testSize;
	cin >> testSize;
	cin.ignore();
	for (int i = 0; i < testSize; ++i)
	{
		getline(cin , line);
		sort(line.begin() , line.end() , comparator);
		cout << line << endl;
		while (nextPermutation(line))
			cout << line << endl;
	}
	return 0;
}

bool nextPermutation(string & text)
{
	vector<int> flag;
	int length = text.length();
	int i , sizeFlag;
	char c;
	flag.push_back(length - 1);
	for (i = length - 2; i >= 0; --i)
		if (compareCharacter(text[i] , text[i + 1]) == -1)
			break;
		else if (compareCharacter(text[i] , text[i + 1]) == 1)
			flag.push_back(i);
	if (i == -1)
		return false;

	sizeFlag = flag.size();
	c = text[i];
	int j;
	for (j = 0; j < sizeFlag; ++j)
		if (compareCharacter(text[flag[j]] , c) == 1)
			break;
	swap(text[i] , text[flag[j]]);
	int temp = (length - i) / 2;
	for (j = 1; j <= temp; ++j)
		swap(text[i + j] , text[length - j]);
	return true;
}

int compareCharacter(char a , char b)
{
	char x , y;
	x = tolower(a);
	y = tolower(b);
	if (x != y)
		if (x < y)
			return -1;
		else
			return 1;
	else
		if (a == b)
			return 0;
		else if (a < b)
			return -1;
		else
			return 1;
}

bool comparator(char const & a ,
				char const & b)
{
	return (compareCharacter(a , b) < 0);
}