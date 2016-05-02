#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::unordered_map;
using std::unordered_set;

string puzzle, answer;
unordered_map<char , bool> checkPuzzle;
unordered_set<char> checkAnswer;
char c;
int length , hangCounter , winCounter;

int main()
{
	int roundNumber;
	while (true)
	{
		cin >> roundNumber;
		cin.ignore();
		if (roundNumber == -1)
			break;
		checkPuzzle.clear();
		checkAnswer.clear();
		hangCounter = 0;
		winCounter = 0;
		getline(cin , puzzle);
		getline(cin , answer);
		length = puzzle.size();
		for (int i = 0; i < length; ++i)
		{
			c = puzzle[i];
			if (checkPuzzle.find(c) == checkPuzzle.end())
			{
				checkPuzzle[c] = false;
				++winCounter;
			}
		}
		length = answer.size();
		for (int i = 0; i < length; ++i)
		{
			c = answer[i];
			if (checkPuzzle.find(c) != checkPuzzle.end())
			{
				if (checkPuzzle[c] == false)
				{
					--winCounter;
					checkPuzzle[c] = true;
					if (winCounter == 0)
						break;
				}
			}
			else
			{
				if (checkAnswer.find(c) != checkAnswer.end())
					continue;
				checkAnswer.insert(c);
				++hangCounter;
				if (hangCounter == 7)
					break;
			}
		}
			
		cout << "Round " << roundNumber << endl;
		if (hangCounter == 7)
			cout << "You lose.";
		else if (winCounter <= 0)
			cout << "You win.";
		else
			cout << "You chickened out.";
		cout << endl;
	}
	return 0;
}