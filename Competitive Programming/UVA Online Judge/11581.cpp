#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;

short grid[2][3][3];
string line;
int testCase , cur , next , result , counter;

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (cin >> testCase , cin.ignore(); testCase > 0; --testCase)
	{
		getline(cin , line);
		for (int i = 0; i < 3; ++i)
		{
			getline(cin , line);
			for (int j = 0; j < 3; ++j)
				grid[0][i][j] = line[j] - '0';
		}
		cur = 0;
		result = -1;
		while (true)
		{
			for (counter = 0; counter < 3; ++counter)
				for (int j = 0; j < 3; ++j)
					if (grid[cur][counter][j] != 0)
						goto break_counter;
		break_counter:
			if (counter != 3)
				++result;
			else
			{
				cout << result << '\n';
				break;
			}
			next = (cur == 0) ? 1 : 0;
			grid[next][0][0] = (grid[cur][0][1] + grid[cur][1][0]) % 2;
			grid[next][0][1] = (grid[cur][0][0] + grid[cur][0][2] + grid[cur][1][1]) % 2;
			grid[next][0][2] = (grid[cur][0][1] + grid[cur][1][2]) % 2;
			grid[next][1][0] = (grid[cur][0][0] + grid[cur][1][1] + grid[cur][2][0]) % 2;
			grid[next][1][1] = (grid[cur][0][1] + grid[cur][1][0] + grid[cur][1][2] + grid[cur][2][1]) % 2;
			grid[next][1][2] = (grid[cur][0][2] + grid[cur][1][1] + grid[cur][2][2]) % 2;
			grid[next][2][0] = (grid[cur][1][0] + grid[cur][2][1]) % 2;
			grid[next][2][1] = (grid[cur][2][0] + grid[cur][1][1] + grid[cur][2][2]) % 2;
			grid[next][2][2] = (grid[cur][2][1] + grid[cur][1][2]) % 2;
			cur = next;
		}
	}
	return 0;
}