#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int input , counter , max , min;
vector<vector<int>> scenario;
vector<int> begin , end;

void updateLight(int i , int j);

int main()
{
	int temp;
	counter = 0;
	scenario.push_back(vector<int>());
	while (true)
	{
		cin >> input;
		if (input != 0)
			scenario[counter].push_back(input);
		else
		{
			cin >> temp;
			++counter;
			if (temp == 0)
				break;
			scenario.push_back(vector<int>());
			scenario[counter].push_back(temp);
		}	
	}
	bool isOut;
	for (int i = 0; i < counter; ++i)
	{
		input = scenario[i].size();
		begin.clear();
		begin.resize(input);
		end.clear();
		end.resize(input);
		isOut = false;
		sort(scenario[i].begin() , scenario[i].end());
		for (int j = 0; j < input; ++j)
		{
			begin[j] = 0;
			end[j] = scenario[i][j] - 5;
		}
		updateLight(i , 0);
		min = begin[input - 1];
		max = input - 1;
		isOut = false;
		while (true)
		{
			int j;
			for (j = input - 1; j >= 0; --j)
			{
				while (end[j] <= min)
					updateLight(i , j);
				if (begin[j] > 18000)
				{
					isOut = true;
					break;
				}
				if (begin[j] >= end[max])
				{
					updateLight(i , max);
					if (begin[j] > begin[max])
						min = begin[j];
					else
						min = begin[max];
					break;
				}
				if (begin[j] > min)
					min = begin[j];
				if (end[j] < end[max])
					max = j;
			}
			if (isOut == true)
			{
				cout << "Signals fail to synchronise in 5 hours" << endl;
				break;
			}
			if (j < 0)
				break;
		}
		if (!isOut)
		{
			temp = min / 3600;
			if (temp <= 9)
				cout << '0';
			cout << temp;
			min %= 3600;
			cout << ':';
			temp = min / 60;
			if (temp <= 9)
				cout << '0';
			cout << temp;
			min %= 60;
			cout << ':';
			if (min <= 9)
				cout << '0';
			cout << min << endl;
		}
	}
	return 0;
}

void updateLight(int i , int j)
{
	begin[j] += scenario[i][j] * 2;
	end[j] = begin[j] + scenario[i][j] - 5;
}