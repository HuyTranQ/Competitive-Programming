#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int testCase, sizePlayer , sizeSnake, sizeRoll;
bool gameOver;
int boardGame[10][10];
vector<short> player;

int main()
{
	int head , tail , roll;
	short temp , row , col;
	cin >> testCase;
	while (testCase > 0)
	{
		player.clear();
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j)
				boardGame[i][j] = 0;
		cin >> sizePlayer >> sizeSnake >> sizeRoll;
		player.resize(sizePlayer , 1);
		gameOver = false;
		while (sizeSnake > 0)
		{
			cin >> head >> tail;
			boardGame[head / 10][head % 10] = tail;
			--sizeSnake;
		}
		while (sizeRoll > 0)
			for (int i = 0; i < sizePlayer; ++i)
			{
				cin >> roll;
				if (!gameOver)
				{
					player[i] += roll;
					temp = player[i];
					if (temp < 100)
					{
						row = temp / 10;
						col = temp % 10;
						if (boardGame[row][col] != 0)
							player[i] = boardGame[row][col];
					}
					if (player[i] >= 100)
					{
						gameOver = true;
						player[i] = 100;
					}
				}
				--sizeRoll;
				if (sizeRoll == 0)
					break;
			}
		for (int i = 1; i <= sizePlayer; ++i)
			cout << "Position of player " << i << " is " << player[i - 1] << ".\n";
		--testCase;
	}
	return 0;
}