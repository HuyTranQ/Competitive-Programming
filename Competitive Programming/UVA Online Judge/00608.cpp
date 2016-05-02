#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int testCase , length , max;
bool isUp;
string first , second , balance;
vector<int> check(12);
vector<int> up(12);
int unbalance[2] = { 1 , -1 };
int index;

int main()
{
	for (cin >> testCase; testCase > 0; --testCase)
	{
		for (int i = 0; i < 12; ++i)
		{
			check[i] = 0;
			up[i] = 0;
		}
		for (int i = 0; i < 3; ++i)
		{
			cin >> first >> second >> balance;
			length = first.length();
			if (balance[0] == 'e')
			{
				for (int j = 0; j < length; ++j)
				{
					check[first[j] - 'A'] = -1;
					check[second[j] - 'A'] = -1;
				}
			}
			else
			{
				isUp = (balance[0] == 'u');
				for (int j = 0; j < length; ++j)
				{
					index = first[j] - 'A';
					if (check[index] != -1)
					{
						if (up[index] != 0 &&
							up[index] != unbalance[!isUp])
							check[index] = -1;
						else
						{
							up[index] = unbalance[!isUp];
							++check[index];
						}
					}
					index = second[j] - 'A';
					if (check[index] != -1)
					{
						if (up[index] != 0 &&
							up[index] != unbalance[isUp])
							up[index] = -1;
						else
						{
							up[index] = unbalance[isUp];
							++check[index];
						}
					}
				}
			}
		}
		max = 0;
		for (int i = 1; i < 12; ++i)
			if (check[i] > check[max])
				max = i;
		cout << (char) (max + 'A') << " is the counterfeit coin and it is " << ((up[max] == -1) ? "light" : "heavy") << ".\n";
	}
	return 0;
}