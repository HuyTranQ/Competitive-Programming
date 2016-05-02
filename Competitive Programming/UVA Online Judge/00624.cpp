#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

const int max = 20000;

int length , sizeTrack;
vector<int> track(21);
vector<vector<int>> table(21 , vector<int>(max));

void print(int index , int duration);

int main()
{
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < max; ++i)
		table[0][i] = 0;
	for (int i = 0; i < 21; ++i)
		table[i][0] = 0;
	while (cin >> length)
	{
		cin >> sizeTrack;
		for (int i = 1; i <= sizeTrack; ++i)
			cin >> track[i];
		for (int i = 1; i <= sizeTrack; ++i)
			for (int j = 1; j <= length; ++j)
			{
				table[i][j] = table[i - 1][j];
				if (track[i] <= j)
				{
					int t = table[i - 1][j - track[i]] + track[i];
					if (table[i][j] < t)
						table[i][j] = t;
				}
			}
		print(sizeTrack , length);
		cout << "sum:" << table[sizeTrack][length] << '\n';
	}
	return 0;
}

void print(int index , int duration)
{
	if (index == 0)
		return;
	if (table[index][duration] == table[index - 1][duration])
		print(index - 1 , duration);
	else
	{
		print(index - 1 , duration - track[index]);
		cout << track[index] << ' ';
	}
}