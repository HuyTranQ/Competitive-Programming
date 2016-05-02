#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> number(12);
vector<int> frequency(12);
vector<int> result(12);
vector<int> duplicate(12);
int total , size;
bool possible;

void sum_it_up(int index ,
			   int counter ,
			   int total);

int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> total)
	{
		int dup_size;
		cin >> dup_size;
		if (dup_size == 0)
			break;
		size = 0;
		frequency[0] = 1;
		cin >> number[0];
		for (int i = 1; i < dup_size; ++i)
		{
			int value;
			cin >> value;
			if (value == number[size])
				++frequency[size];
			else
			{
				++size;
				number[size] = value;
				frequency[size] = 1;
			}
		}
		++size;
		possible = false;
		cout << "Sums of " << total << ":\n";
		sum_it_up(0 , 0 , total);
		if (!possible)
			cout << "NONE\n";
	}
	return 0;
}

void sum_it_up(int index , int counter , int total)
{
	if (total == 0)
	{
		for (int i = 0; ; ++i)
		{
			for (int j = 1; ; ++j)
			{
				cout << result[i];
				if (j == duplicate[i])
					break;
				cout << '+';
			}
			if (i == counter - 1)
				break;
			cout << '+';
		}
		cout << '\n';
		possible = true;
		return;
	}
	if (index == size)
		return;
	int max_duplicate = total / number[index];
	if (max_duplicate > frequency[index])
		max_duplicate = frequency[index];
	int sum = max_duplicate * number[index];
	duplicate[counter] = max_duplicate;
	result[counter] = number[index];
	while (sum > 0)
	{
		sum_it_up(index + 1 , counter + 1 , total - sum);
		sum -= number[index];
		--duplicate[counter];
	}
	sum_it_up(index + 1 , counter , total);
}