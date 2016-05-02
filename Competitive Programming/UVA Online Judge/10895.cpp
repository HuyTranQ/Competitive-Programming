#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::vector;

int m , n;
map<int , map<int , int>> matrix;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> m)
	{
		cin >> n;
		cout << n << ' ' << m << '\n';
		for (int i = 0; i < n; ++i)
			matrix[i];
		for (int row = 0; row < m; ++row)
		{
			int size;
			cin >> size;
			vector<int> position(size);
			for (int i = 0; i < size; ++i)
				cin >> position[i];
			for (int i = 0; i < size; ++i)
			{
				int value;
				cin >> value;
				matrix[position[i] - 1][row] = value;
			}
		}
		map<int , map<int , int>>::iterator it = matrix.begin() , end = matrix.end();
		while (it != end)
		{
			map<int , int>::iterator jt = it->second.begin() , jend = it->second.end();
			cout << it->second.size();
			while (jt != jend)
			{
				cout << ' ' << (jt->first + 1);
				++jt;
			}
			cout << '\n';
			jt = it->second.begin();
			if (jt != jend)
				while (true)
				{
					cout << jt->second;
					++jt;
					if (jt == jend)
						break;
					cout << ' ';
				}
			cout << '\n';
			++it;
		}
		matrix.clear();
	}
	return 0;
}