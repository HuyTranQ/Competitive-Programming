#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;

struct Font
{
	void virtual print();
	int limit;
	int width;
};

struct FontC1 : public Font
{
	FontC1()
	{
		limit = 60;
		width = 1;
	}
	void print();
};

struct FontC5 : public Font
{
	FontC5()
	{
		limit = 10;
		width = 6;
	}
	void print();
	void printPartial(int colBegin , 
					  int colEnd,
					  int index);
};

vector<vector<string>> alphabet = 
{
	{ ".***..", "*...*.", "*****.", "*...*.", "*...*.", },
	{ "****..", "*...*.", "****..", "*...*.", "****..", },
	{ ".****.", "*...*.", "*.....", "*.....", ".****.", },
	{ "****..", "*...*.", "*...*.", "*...*.", "****..", },
	{ "*****.", "*.....", "***...", "*.....", "*****.", },
	{ "*****.", "*.....", "***...", "*.....", "*.....", },
	{ ".****.", "*.....", "*..**.", "*...*.", ".***..", },
	{ "*...*.", "*...*.", "*****.", "*...*.", "*...*.", },
	{ "*****.", "..*...", "..*...", "..*...", "*****.", },
	{ "..***.", "...*..", "...*..", "*..*..", ".**...", },
	{ "*...*.", "*..*..", "***...", "*..*..", "*...*.", },
	{ "*.....", "*.....", "*.....", "*.....", "*****.", },
	{ "*...*.", "**.**.", "*.*.*.", "*...*.", "*...*.", },
	{ "*...*.", "**..*.", "*.*.*.", "*..**.", "*...*.", },
	{ ".***..", "*...*.", "*...*.", "*...*.", ".***..", },
	{ "****..", "*...*.", "****..", "*.....", "*.....", },
	{ ".***..", "*...*.", "*...*.", "*..**.", ".****.", },
	{ "****..", "*...*.", "****..", "*..*..", "*...*.", },
	{ ".****.", "*.....", ".***..", "....*.", "****..", },
	{ "*****.", "*.*.*.", "..*...", "..*...", ".***..", },
	{ "*...*.", "*...*.", "*...*.", "*...*.", ".***..", },
	{ "*...*.", "*...*.", ".*.*..", ".*.*..", "..*...", },
	{ "*...*.", "*...*.", "*.*.*.", "**.**.", "*...*.", },
	{ "*...*.", ".*.*..", "..*...", ".*.*..", "*...*.", },
	{ "*...*.", ".*.*..", "..*...", "..*...", "..*...", },
	{ "*****.", "...*..", "..*...", ".*....", "*****.", },
	{ "......", "......", "......", "......", "......", }
};

string command , font , argument;
vector<string> page;
string separator = string(60 , '-');
int row , col , length , begin , end , typeFont;
FontC1 printerC1;
FontC5 printerC5;
Font * printer;

int indexAlpha(char c);
void printLeft();
void printRight();
void printCenter();
void printPosition();
void printAlphabet(char c);
void printFontC1(int begin , int end);
void printFontC5(int begin , int end);

int main()
{
	while (cin >> command)
	{
		page = vector<string>(60 , string(60 , '.'));
		if (command[1] != 'E')
			do
			{
				cin >> font >> row;
				if (command[1] == 'P')
				{
					cin >> col;
					--col;
				}
				else
					col = 0;
				cin.ignore();
				cin.ignore();
				getline(cin , argument);
				argument = argument.substr(0 , argument.find_last_of('|'));
				length = argument.length();
				--row;
				if (font[1] == '1')
					printer = &printerC1;
				else
					printer = &printerC5;
				switch (command[1])
				{
					case 'C':
						printCenter();
						break;
					case 'L':
						printLeft();
						break;
					case 'R':
						printRight();
						break;
					case 'P':
						printPosition();
						break;
					default:
						break;
				}
				cin >> command;
			} while (command[1] != 'E');
		for (int i = 0; i < 60; ++i)
			cout << page[i] << endl;
		cout << endl << separator << endl << endl;
	}
	return 0;
}

void printLeft()
{
	begin = 0;
	col = 0;
	end = (length > printer->limit) ? printer->limit : length;
	printer->print();
}

void printRight()
{
	end = length;
	if (length > printer->limit)
	{
		begin = length - printer->limit;
		col = 0;
	}
	else
	{
		begin = 0;
		col = 60 - length * printer->width;
	}
	printer->print();
}

void printCenter()
{
	int half = length / 2;
	int remain = length % 2;
	int width = printer->width;
	int temp = width * length;
	if (temp % 2 == 1)
	{
		if (half > 30)
		{
			begin = half - 30;
			end = half + 30;
			col = 0;
		}
		else
		{
			begin = 0;
			end = length;
			col = 30 - half;
		}
	}
	else if (remain == 1)
	{
		if (length <= 9)
		{
			begin = 0;
			end = length;
			col = 30 - half * 6 - 3;
		}
		else
		{
			begin = half - 4;
			end = half + 5;
			col = 0;
			printerC5.printPartial(3 , 6 , indexAlpha(argument[begin - 1]));
			col = 57;
			printerC5.printPartial(0 , 3 , indexAlpha(argument[end]));
			col = 3;
		}
	}
	else
	{
		int limitHalf = printer->limit / 2;
		if (half > limitHalf)
		{
			begin = half - limitHalf;
			end = half + limitHalf;
			col = 0;
		}
		else
		{
			begin = 0;
			end = length;
			col = 30 - half * width;
		}
	}
	printer->print();
}

void printPosition()
{
	int width = printer->width;
	begin = 0;
	if (length * width > 60 - col)
	{
		end = (60 - col) / width;
		int t = col;
		col = col + end * width;
		printerC5.printPartial(0 , 60 - col , indexAlpha(argument[end]));
		col = t;
	}
	else
		end = length;
	printer->print();
}

int indexAlpha(char c)
{
	if (c == ' ')
		return 26;
	else
		return c - 'A';
}

void FontC1::print()
{
	int colLimit = col + end;
	if (colLimit > 60)
		colLimit = 60;
	for (int i = col; i < colLimit; ++i)
		if (argument[i - col + begin] != ' ')
			page[row][i] = argument[i - col + begin];
}

void FontC5::print()
{
	int offset = col;
	int index , rowLimit;
	rowLimit = (row > 55) ? 60 : row + 5;
	for (int i = begin; i < end; ++i)
	{
		index = indexAlpha(argument[i]);
		for (int j = row; j < rowLimit; ++j)
			for (int k = 0; k < 6; ++k)
				if (alphabet[index][j - row][k] == '*')
					page[j][k + offset] = alphabet[index][j - row][k];
		offset += 6;
	}
}

void FontC5::printPartial(int colBegin,
						  int colEnd,
						  int index)
{
	int rowLimit;
	rowLimit = (row > 55) ? 60 : row + 5;
	for (int i = row; i < rowLimit; ++i)
		for (int k = colBegin; k < colEnd; ++k)
			if (alphabet[index][i - row][k] == '*')
				page[i][col + k - colBegin] = alphabet[index][i - row][k];
}

void Font::print()
{
}