#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

string line;
int length , frameCounter , rollCounter , bonusCount , bonusNow, score;
char roll;
bool finalRoll;

int main()
{
	while (true)
	{
		getline(cin , line);
		if (line[0] == 'G')
			break;
		length = line.size();
		frameCounter = 10;
		bonusCount = 0;
		score = 0;
		finalRoll = true;
		for (rollCounter = 0; rollCounter < length; rollCounter += 2)
		{
			roll = line[rollCounter];
			if (roll == 'X')
			{
				roll = 10;
				bonusNow = (frameCounter > 0) ? 2 : 0;
				finalRoll = true;
			}
			else 
			{
				finalRoll = !finalRoll;
				if (roll == '/')
				{
					roll = 10 - (line[rollCounter - 2] - '0');
					bonusNow = 1;
				}
				else
				{
					roll = line[rollCounter] - '0';
					bonusNow = 0;
				}
			}
			if (frameCounter > 0)
				score += roll;
			if (bonusCount > 0)
			{
				int weight = (bonusCount > 2) ? 2 : 1;
				score += weight * roll;
				bonusCount -= weight;
			}
			bonusCount += bonusNow;
			if (finalRoll)
				--frameCounter;
		}
		cout << score << endl;
	}
	return 0;
}