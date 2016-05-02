#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int boardBingo[5][5];
int row[5] , col[5] , dia[2];
int testSize , counter , number , result;

bool isBingo(int number);

int main()
{
	cin >> testSize;
	while (testSize > 0)
	{
		dia[0] = 4;
		dia[1] = 4;
		for (int i = 0; i < 5; ++i)
			if (i == 2)
			{
				cin >> boardBingo[2][0] >> boardBingo[2][1] >> boardBingo[2][3] >> boardBingo[2][4];
				row[2] = 4;
				col[2] = 4;
			}
			else
			{
				row[i] = 5;
				col[i] = 5;
				for (int j = 0; j < 5; ++j)
					cin >> boardBingo[i][j];
			}
		counter = 1;
		do
		{
			cin >> number;
			if (isBingo(number))
				break;
			++counter;
		} while (counter <= 75);
		result = counter;
		do
		{
			cin >> number;
			++counter;
		} while (counter < 75);
		cout << "BINGO after "<< result << " numbers announced" << endl;
		--testSize;
	}
	return 0;
}

bool isBingo(int number)
{
	int numRow , numCol;
	numCol = number / 15 - (number % 15 == 0);
	numRow = 0;
	while (true)
	{
		if (numRow == 5)
			return false;
		if (boardBingo[numRow][numCol] == number)
			break;
		++numRow;
	}
	if (row[numRow] == 1)
		return true;
	else
		--row[numRow];
	if (col[numCol] == 1)
		return true;
	else
		--col[numCol];
	if (numRow == numCol)
		if (dia[0] == 1)
			return true;
		else
			--dia[0];
	if (numRow == 4 - numCol)
		if (dia[1] == 1)
			return true;
		else
			--dia[1];
	return false;
}