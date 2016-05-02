#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::vector;

int big , small , limit;
int result[4];
bool isMatched;
vector<string> bigSquare , smallSquare;

void print()
{
	for (int x = 0; x < small; ++x)
	{
		int offset = small - x - 1;
		for (int y = 0; y < small; ++y)
			cout << smallSquare[y][offset];
		cout << '\n';
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (true)
	{
		cin >> big >> small;
		if (big == 0)
			break;
		cin.ignore();
		bigSquare.resize(big);
		smallSquare.resize(small);
		result[0] = result[1] = result[2] = result[3] = 0;
		for (int i = 0; i < big; ++i)
			getline(cin , bigSquare[i]);
		for (int i = 0; i < small; ++i)
			getline(cin , smallSquare[i]);
		limit = big - small + 1;
		for (int oX = 0; oX < limit; ++oX)
			for (int oY = 0; oY < limit; ++oY)
			{
				isMatched = true;
				for (int x = 0; x < small; ++x)
					for (int y = 0; y < small; ++y)
						if (smallSquare[x][y] != bigSquare[oX + x][oY + y])
						{
							isMatched = false;
							goto break_000;
						}
			break_000:
				result[0] += isMatched;

				isMatched = true;
				for (int x = 0; x < small; ++x)
					for (int y = 0; y < small; ++y)
						if (smallSquare[small - y - 1][x] != bigSquare[oX + x][oY + y])
						{
							isMatched = false;
							goto break_090;
						}
			break_090:
				result[1] += isMatched;

				isMatched = true;
				for (int x = 0; x < small; ++x)
				{
					int offset = small - x - 1;
					for (int y = 0; y < small; ++y)
						if (smallSquare[offset][small - y - 1] != bigSquare[oX + x][oY + y])
						{
							isMatched = false;
							goto break_180;
						}
				}
			break_180:
				result[2] += isMatched;

				isMatched = true;
				for (int x = 0; x < small; ++x)
				{
					int offset = small - x - 1;
					for (int y = 0; y < small; ++y)
						if (smallSquare[y][offset] != bigSquare[oX + x][oY + y])
						{
							isMatched = false;
							goto break_270;
						}
				}
			break_270:
				result[3] += isMatched;
			}
		for (int i = 0; ; ++i)
		{
			cout << result[i];
			if (i == 3)
				break;
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}