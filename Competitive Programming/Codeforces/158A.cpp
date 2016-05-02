#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int contest , pivot;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> contest >> pivot;
	vector<int> contestant(contest);
	for (int i = 0; i < contest; ++i)
		cin >> contestant[i];
	int result;
	if (contestant[pivot - 1] > 0)
	{
		for (result = pivot; result < contest; ++result)
			if (contestant[result] != contestant[pivot - 1])
				break;
	}
	else
	{
		result = pivot - 1;
		while (result >= 0)
		{
			if (contestant[result] > 0)
				break;
			--result;
		}
		++result;
	}
	cout << result;
	return 0;
}