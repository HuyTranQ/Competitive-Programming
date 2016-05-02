#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int m , n;
vector<string> result;
vector< vector<string> > finalResult;
string line;
int counter = 0;

int main()
{
	while (true)
	{
		cin >> m >> n;
		if (m == 0)
			break;
		cin.ignore();
		result.clear();
		for (int i = 0; i < m; ++i)
		{
			getline(cin , line);
			for (int j = 0; j < n; ++j)
				if (line[j] != '*')
				{
					if (line[j] == '.')
						line[j] = '0';
					if (j > 0 && line[j - 1] == '*')
						++line[j];
					if (j < n - 1 && line[j + 1] == '*')
						++line[j];
					if (i != 0)
						for (int k = -1; k < 2; ++k)
							if (0 <= j + k && j + k < n && result[i - 1][j + k] == '*')
								++line[j];
				}
				else if (i > 0)
						for (int k = -1; k < 2; ++k)
							if (0 <= j + k && j + k < n && result[i - 1][j + k] != '*')
								++result[i - 1][j + k];
			result.push_back(line);
		}
		finalResult.push_back(result);
		++counter;
	}
	for (int i = 0; i < counter; ++i)
	{
		m = finalResult[i].size();
		cout << "Field #" << (i + 1) << ":" << endl;
		for (int j = 0; j < m; ++j)
			cout << finalResult[i][j] << endl;
		if (i != counter - 1)
			cout << endl;
	}
	return 0;
}