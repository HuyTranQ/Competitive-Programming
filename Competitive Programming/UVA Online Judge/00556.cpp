#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

int width , height , forward , right , x , y , a , b;
vector<string> maze;
vector<int> result(5);
vector<vector<int>> track;
int xOffset[] = { 1 , 0 , -1 , 0 };
int yOffset[] = { 0 , 1 , 0 , -1 };

void checkTrack(int x , int y);

int main()
{
	while (true)
	{
		cin >> height >> width;
		if (width == 0)
			break;
		cin.ignore();
		maze.clear();
		maze.resize(height);
		track.clear();
		track.resize(height , vector<int>(width , 0));
		for (int i = 0; i < 5; ++i)
			result[i] = 0;
		for (int i = 0; i < height; ++i)
			getline(cin , maze[i]);
		forward = 1;
		right = 0;
		x = height - 1;
		y = 0;
		checkTrack(x , y);
		while (true)
		{
			a = x + xOffset[right];
			if (0 <= a && a < height)
			{
				b = y + yOffset[right];
				if (0 <= b && b < width)
					if (maze[a][b] == '0')
					{
						forward = right;
						right = (right + 3) % 4;
					}
			}
			a = x + xOffset[forward];
			if (0 <= a && a < height)
			{
				b = y + yOffset[forward];
				if (0 <= b && b < width)
					if (maze[a][b] == '0')
					{
						if (a == height - 1 &&
							b == 0)
							break;
						x = a;
						y = b;
						checkTrack(x , y);
						continue;
					}
			}
			right = forward;
			forward = (forward + 1) % 4;
		}
		for (int i = 0; i < height; ++i)
			for (int j = 0; j < width; ++j)
				if (maze[i][j] == '0' &&
					track[i][j] == 0)
					++result[0];
		for (int i = 0; i < 5; ++i)
			cout << std::right << std::setw(3) << result[i];
		cout << endl;
	}
	return 0;
}

void checkTrack(int x , int y)
{
	if (track[x][y] >= 0 &&
		track[x][y] <= 5)
	{
		if (track[x][y] > 0)
			--result[track[x][y]];
		if (track[x][y] < 5)
			++result[track[x][y] + 1];
	}
	++track[x][y];
}