#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int princess[3] , prince[2];
bool checkPrincess[3] , checkPrince[2];

bool playJollo(int counter,
			   int win,
			   int & result);

int main()
{
	int result;
	while (true)
	{
		cin >> princess[0] >> princess[1] >> princess[2];
		cin >> prince[0] >> prince[1];
		if (princess[0] == 0)
			break;
		checkPrincess[0] = checkPrincess[1] = checkPrincess[2] = false;
		checkPrince[0] = checkPrince[1] = false;
		result = 0;
		playJollo(0 , 0 , result);
		if (result == 0)
		{
			result = 1;
			while (true)
			{
				if (result == princess[0] ||
					result == princess[1] ||
					result == princess[2] ||
					result == prince[0] ||
					result == prince[1])
				{
					++result;
					continue;
				}
				break;
			}
		}
		else if (result > 52)
			result = -1;
		cout << result << endl;
	}
	return 0;
}

bool playJollo(int counter,
			   int win,
			   int & result)
{
	if (counter == 2)
	{
		if (win == 0)
		{
			result = -1;
			return false;
		}
		if (win == 1)
		{
			int i;
			for (i = 0; checkPrincess[i]; ++i);
			if (princess[i] >= result)
			{
				result = princess[i] + 1;
				while (true)
				{
					if (result == princess[0] ||
						result == princess[1] ||
						result == princess[2] ||
						result == prince[0] ||
						result == prince[1])
					{
						++result;
						continue;
					}
					break;
				}
			}
		}
		return true;
	}
	for (int i = counter; i < 3; ++i)
		if (!checkPrincess[i])
			for (int j = 0; j < 2; ++j)
				if (!checkPrince[j])
				{
					checkPrincess[i] = true;
					checkPrince[j] = true;
					if (!playJollo(counter + 1 , win + (prince[j] > princess[i]) , result))
						return false;
					checkPrincess[i] = false;
					checkPrince[j] = false;
				}
	return true;
}