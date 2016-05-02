#include <iostream>

using std::cin;
using std::cout;

int dimension , size , max , current;
int weight[17000] , potency[17000];

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> dimension)
	{
		size = 1 << dimension;
		for (int i = 0; i < size; ++i)
			cin >> weight[i];
		for (int i = 0; i < size; ++i)
		{
			potency[i] = 0;
			for (int j = 1; j < size; j <<= 1)
				potency[i] += weight[i ^ j];
		}
		max = 0;
		for (int i = 0; i < size; ++i)
			for (int j = 1; j < size; j <<= 1)
			{
				current = potency[i] + potency[i ^ j];
				if (current > max)
					max = current;
			}
		cout << max << '\n';
	}
	return 0;
}