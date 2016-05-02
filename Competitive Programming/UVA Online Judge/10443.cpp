#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;

int testCase , row , col , day , a , b;
bool isChanged;
vector<string> grid[2];

bool check(int x , int y);

int main()
{
	cin >> testCase;
	while (true)
	{
		cin >> row >> col >> day;
		--testCase;
		if (row == 0 || col == 0)
			continue;
		cin.ignore();
		grid[0].clear();
		grid[1].clear();
		grid[0].resize(row);
		grid[1].resize(row);
		for (int i = 0; i < row; ++i)
		{
			getline(cin , grid[0][i]);
			grid[1][i].resize(grid[0][i].size());
		}
		int t;
		a = 0;
		b = 1;
		isChanged = false;
		for (int i = 0; i < day; ++i)
		{
			for (int j = 0; j < row; ++j)
				for (int k = 0; k < col; ++k)
					isChanged = check(j , k) || isChanged;
			t = a;
			a = b;
			b = t;
			if (!isChanged)
				break;
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
				cout << grid[a][i][j];
			cout << endl;
		}
		if (testCase == 0)
			break;
		else
			cout << endl;
	}
	return 0;
}

bool check(int x , int y)
{
	char upperHand;
	char type = grid[a][x][y];
	if (type == 'R')
		upperHand = 'P';
	else if (type == 'S')
		upperHand = 'R';
	else
		upperHand = 'S';
	if (x > 0 && grid[a][x - 1][y] == upperHand)
	{
		grid[b][x][y] = upperHand;
		return true;
	}
	if (x < row - 1 && grid[a][x + 1][y] == upperHand)
	{
		grid[b][x][y] = upperHand;
		return true;
	}
	if (y > 0 && grid[a][x][y - 1] == upperHand)
	{
		grid[b][x][y] = upperHand;
		return true;
	}
	if (y < col - 1 && grid[a][x][y + 1] == upperHand)
	{
		grid[b][x][y] = upperHand;
		return true;
	}
	grid[b][x][y] = grid[a][x][y];
	return false;
}