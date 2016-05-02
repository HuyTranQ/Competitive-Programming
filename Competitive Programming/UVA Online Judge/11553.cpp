#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::vector;

size_t testCase , size;
int result;
vector<vector<int>> board(8 , vector<int>(8));
vector<bool> check(8 , true);

void optimizeBoard(int column ,
				   int sum);

int main()
{
	std::ios::sync_with_stdio(false);
	for (cin >> testCase; testCase > 0; --testCase)
	{
		cin >> size;
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				cin >> board[i][j];
		result = INT_MAX;
		optimizeBoard(0 , 0);
		cout << result << '\n';
	}
	return 0;
}

void optimizeBoard(int column ,
		   		   int sum)
{
	if (column == size)
	{
		if (sum < result)
			result = sum;
		return;
	}
	for (int i = 0; i < size; ++i)
		if (check[i])
		{
			check[i] = false;
			optimizeBoard(column + 1 , sum + board[i][column]);
			check[i] = true;
		}
}