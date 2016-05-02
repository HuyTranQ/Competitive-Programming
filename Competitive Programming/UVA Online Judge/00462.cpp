#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string line;
	string rankChar = "AKQJ";
	string suitChar = "SHDC";
	int suit[4];
	int rank[4];
	bool track[4][4];
	bool stop[4];
	int counter , sum , pointAdd , maxSuit , index;
	while (true)
	{
		getline(cin , line);
		if (line.size() == 0)
			break;
		for (int i = 0; i < 4; ++i)
		{
			suit[i] = 0;
			rank[i] = 0;
			stop[i] = false;
			for (int j = 0; j < 4; ++j)
				track[i][j] = false;
		}
		sum = 0;
		pointAdd = 0;
		maxSuit = 0;
		for (int i = 0; i < 39; i += 3)
		{
			int k;
			for (k = 0; k < 4; ++k)
				if (line[i + 1] == suitChar[k])
				{
					++suit[k];
					break;
				}
			int j;
			for (j = 0; j < 4; ++j)
				if (line[i] == rankChar[j])
				{
					track[k][j] = true;
					++rank[k];
					break;
				}
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (track[i][j] == true)
				{
					sum += (4 - j);
					if (suit[i] <= j)
						--sum;
					if (j < 3)
						stop[i] = stop[i] || (suit[i] >= j + 1);
				}
			}
			if (suit[i] > maxSuit)
			{
				index = i;
				maxSuit = suit[i];
			}
			if (suit[i] == 2)
				pointAdd += 1;
			else if (suit[i] < 2)
				pointAdd += 2;
		}
		if (sum >= 16 &&
			stop[0] && stop[1] && stop[2] && stop[3])
			cout << "BID NO-TRUMP";
		else
		{
			sum += pointAdd;
			if (sum < 14)
				cout << "PASS";
			else
				cout << "BID " << suitChar[index];
		}
		cout << endl;
	}
	return 0;
}