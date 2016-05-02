#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;

string line;
int size , it , min;
char terminal[28];

int main()
{
	std::ios_base::sync_with_stdio(false);
	for (int j = 0; j < 26; ++j)
		terminal[j] = 0;
	terminal[26] = '[';
	for (int i = 1; getline(cin , line); ++i)
	{
		if (line[0] == 'e')
			break;
		size = line.size();
		it = -1;
		for (int j = 0; j < size; ++j)
		{
			int k;
			min = 26;
			for (k = it; k >= 0; --k)
				if (line[j] <= terminal[k])
					if (terminal[k] < terminal[min])
						min = k;
			if (min == 26)
			{
				++it;
				terminal[it] = line[j];
			}
			else
				terminal[min] = line[j];
		}
		cout << "Case " << i << ": " << (it + 1) << '\n';
		for (int j = 0; j <= it; ++j)
			terminal[j] = 0;
	}
	return 0;
}