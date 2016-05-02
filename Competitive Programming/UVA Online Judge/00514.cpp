#include <iostream>

using std::cin;
using std::cout;

struct Span
{
	int begin , end;
};

int trainSize , counter;
int coach , it;
Span station[1000];
bool possible;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> trainSize)
	{
		if (trainSize == 0)
			break;
		while (true)
		{
			int i = 0;
			cin >> coach;
			if (coach == 0)
				break;
			it = -1;
			counter = 1;
			possible = true;
			while (true)
			{
				if (it == -1 ||
					station[it].end != coach)
				{
					if (counter > coach)
					{
						possible = false;
						while (true)
						{
							++i;
							if (i == trainSize)
								break;
							cin >> coach;
						}
						break;
					}
					else if (counter == coach)
						++counter;
					else
					{
						++it;
						station[it].begin = counter;
						station[it].end = coach - 1;
						counter = coach + 1;
					}
				}
				else if (station[it].begin == station[it].end)
					--it;
				else
					--station[it].end;
				++i;
				if (i == trainSize)
					break;
				cin >> coach;
			}
			cout << (possible ? "Yes" : "No") << '\n';
		}
		cout << "\n";
	}
	return 0;
}