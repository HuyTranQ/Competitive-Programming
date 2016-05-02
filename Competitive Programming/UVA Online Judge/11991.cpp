#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::vector;

int sizeArray , sizeQuery;
map<int , vector<int>> data;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> sizeArray)
	{
		cin >> sizeQuery;
		for (int i = 1; i <= sizeArray; ++i)
		{
			int number;
			cin >> number;
			data[number].push_back(i);
		}
		while (sizeQuery > 0)
		{
			int number , position;
			cin >> position >> number;
			if (data[number].size() < position)
				cout << 0;
			else
				cout << data[number][position - 1];
			cout << '\n';
			--sizeQuery;
		}
		data.clear();
	}
	return 0;
}