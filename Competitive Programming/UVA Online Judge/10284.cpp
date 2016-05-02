#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

struct SpecialPiece
{
	char c;
	int a , b;
	SpecialPiece()
	{

	}
	SpecialPiece(char c , int a , int b) : c(c) , a(a) , b(b)
	{

	}
};

bool isBlack;
string line;
char c;
int length , row , col , result;
int chessBoard[8][8];
vector<SpecialPiece> listPiece;


void checkPawn();
void checkRook();
void checkKnight();
void checkBishop();
void checkKing();
void checkSquare(int a, int b);

void print()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
			cout << chessBoard[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	while (true)
	{
		getline(cin , line);
		length = line.size();
		if (length == 0)
			break;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				chessBoard[i][j] = 0;
		row = 0;
		col = 0;
		result = 64;
		listPiece.clear();
		for (int i = 0; i < length; ++i)
		{
			c = line[i];
			if (c == '/')
			{
				++row;
				col = 0;
			}
			else if ('0' < c && c < '9')
				col += c - '0';
			else
			{
				if (chessBoard[row][col] == 0)
					--result;
				chessBoard[row][col] = 2;
				if ('a' < c && c < 'z')
				{
					isBlack = true;
					c -= 32;
				}
				else
					isBlack = false;
				if (c == 'P')
					checkPawn();
				else if (c == 'N')
					checkKnight();
				else if (c == 'K')
					checkKing();
				else
					listPiece.push_back(SpecialPiece(c , row , col));
				++col;
			}
		}
		length = listPiece.size();
		for (int i = 0; i < length; ++i)
		{
			c = listPiece[i].c;
			row = listPiece[i].a;
			col = listPiece[i].b;
			if (c == 'R')
				checkRook();
			else if (c == 'B')
				checkBishop();
			else 
			{
				checkRook();
				checkBishop();
			}
		}
		cout << result << endl;
	}
	return 0;
}

void checkSquare(int a , int b)
{
	if (chessBoard[a][b] == 0)
	{
		--result;
		chessBoard[a][b] = 1;
	}
}

void checkPawn()
{
	int newRow = row + ((isBlack) ? 1 : -1);
	if (0 <= newRow && newRow < 8)
	{
		if (col > 0)
			checkSquare(newRow , col - 1);
		if (col < 7)
			checkSquare(newRow, col + 1);
	}
}

void checkRook()
{
	static int offsetX[] = { -1 , 0 , 1 , 0 };
	static int offsetY[] = { 0 , -1 , 0 , 1 };
	int a , b;
	for (int i = 0; i < 4; ++i)
		for (int j = 1; j < 8; ++j)
		{
			a = row + offsetX[i] * j;
			b = col + offsetY[i] * j;
			if (a < 0 || a > 7 || b < 0 || b > 7 ||
				chessBoard[a][b] == 2)
				break;
			checkSquare(a , b);
		}
}

void checkKnight()
{
	int a , b;
	static int offset[] = { 1 , 2 };
	static int coef[] = { -1 , 1 };
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
			{
				a = row + coef[j] * offset[i];
				b = col + coef[k] * offset[(i + 1) % 2];
				if (a < 0 || a > 7 || b < 0 || b > 7)
					continue;
				checkSquare(a , b);
			}
}

void checkBishop()
{
	static int offsetX[] = { -1 , -1 , 1 , 1 };
	static int offsetY[] = { -1 , 1 , -1 , 1 };
	int a , b;
	for (int i = 0; i < 4; ++i)
		for (int j = 1; j < 8; ++j)
		{
			a = row + offsetX[i] * j;
			b = col + offsetY[i] * j;
			if (a < 0 || 7 < a || b < 0 || 7 < b ||
				chessBoard[a][b] == 2)
				break;
			checkSquare(a , b);
		}
}

void checkKing()
{
	static int offset[3] = { -1 , 0 , 1 };
	int a , b;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			a = row + offset[i];
			b = col + offset[j];
			if (a < 0 || 7 < a ||
				b < 0 || 7 < b)
				continue;
			checkSquare(a , b);
		}
}