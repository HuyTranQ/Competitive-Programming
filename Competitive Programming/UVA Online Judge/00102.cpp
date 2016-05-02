#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void categorize(vector<vector<int>> const & input ,
				string & resultPosition ,
				int & resultMove ,
				int index ,
				int sum);

int main()
{
	vector<vector<int>> recycleBin(3 , vector<int>(3));
	vector<vector<int>> sum(3 , vector<int>(3));
	string resultPosition = "   ";
	int resultMove;
	string category = "BGC";
	while (cin >> recycleBin[0][0])
	{
		cin >> recycleBin[0][1] >> recycleBin[0][2];
		for (int i = 1; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> recycleBin[i][j];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				sum[i][j] = recycleBin[i][(j + 1) % 3] + recycleBin[i][(j + 2) % 3];
		resultMove = 2147483647;
		categorize(sum , resultPosition , resultMove , 0 , 0);
		cout << resultPosition << ' ' << resultMove << endl;
	}
	return 0;
}

void categorize(vector<vector<int>> const & input ,
				string & resultPosition,
				int & resultMove,
				int index,
				int sum)
{
	static string category = "BGC";
	static string position = "   ";
	static vector<bool> check(3 , false);
	if (index == 3)
	{
		if (sum < resultMove ||
			sum == resultMove &&
			position < resultPosition)
		{
			resultMove = sum;
			resultPosition = position;
		}
		return;
	}
	for (int i = 0; i < 3; ++i)
		if (!check[i])
		{
			position[index] = category[i];
			check[i] = true;
			categorize(input , resultPosition , resultMove , index + 1 , sum + input[index][i]);
			check[i] = false;
		}
}