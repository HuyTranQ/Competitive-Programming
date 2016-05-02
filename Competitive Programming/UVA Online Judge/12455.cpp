#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

size_t testCase;
int length , sizeBar;
vector<int> bar(20);

bool combineBars(int index);

int main()
{
	std::ios::sync_with_stdio(false);
	for (cin >> testCase; testCase > 0; --testCase)
	{
		cin >> length >> sizeBar;
		for (int i = 0; i < sizeBar; ++i)
			cin >> bar[i];
		sort(&bar[0] , &bar[sizeBar]);
		cout << (combineBars(sizeBar - 1) ? "YES" : "NO") << '\n';
	}
	return 0;
}

bool combineBars(int index)
{
	if (length == 0)
		return true;
	while (index >= 0 && bar[index] > length)
		--index;
	if (index < 0)
		return false;
	for (int i = index; i >= 0; --i)
	{
		length -= bar[i];
		if (combineBars(i - 1))
			return true;
		length += bar[i];
	}
	return false;
}