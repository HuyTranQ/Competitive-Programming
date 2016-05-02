#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

string compare , line;
int sizeTest , length , counter , sizeSquare;

bool isPunctuation(char input);
bool isSquarePalindrome();

int main()
{
	compare.resize(10000);
	cin >> sizeTest;
	cin.ignore();
	for (int i = 1; i <= sizeTest; ++i)
	{
		getline(cin , line);
		length = line.length();
		counter = 0;
		for (int i = 0; i < length; ++i)
			if (isPunctuation(line[i]))
				continue;
			else
			{
				compare[counter] = line[i];
				++counter;
			}
		cout << "Case #" << i << ":\n";
		if (isSquarePalindrome())
			cout << sizeSquare << endl;
		else
			cout << "No magic :(" << endl;
	}
	return 0;
}

bool isPunctuation(char input)
{
	return (input == ' ' || input == ',' || input == '.' ||
			input == '?' || input == '!' ||
			input == '(' || input == ')');
}

bool isSquarePalindrome()
{
	if (counter == 0)
		return true;
	sizeSquare = (int) sqrt(counter);
	if (sizeSquare * sizeSquare != counter)
		return false;
	int t = -sizeSquare , a , b;
	for (int i = 0; i < sizeSquare; ++i)
	{
		t += sizeSquare;
		for (int j = i + 1; j < sizeSquare; ++j)
		{
			a = t + j;
			b = j * sizeSquare + i;
			if (compare[a] != compare[b])
				return false;
			--a;
			b = (sizeSquare - j) * sizeSquare + sizeSquare - i - 1;
			if (compare[a] != compare[b])
				return false;
		}
	}
	return true;
}