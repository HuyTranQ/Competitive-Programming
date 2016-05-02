#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::vector;
using std::forward_list;

struct Area
{
	bool isAwake;
	int awakeNeighbor;
	forward_list<int> neighbor;
	Area() : isAwake(false) , awakeNeighbor(0)
	{}
};

int sizeArea;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> sizeArea)
	{
		vector<Area> listArea(26);
		int sizeConnection;
		string directAwake;
		int result = 0;
		cin >> sizeConnection;
		cin.ignore();
		while (getline(cin , directAwake) &&
			   directAwake.empty());
		int length = directAwake.length();
		for (int i = 0; i < sizeConnection; ++i)
		{
			string connection;
			getline(cin , connection);
			int a = connection[0] - 'A';
			int b = connection[1] - 'A';
			listArea[a].neighbor.push_front(b);
			listArea[b].neighbor.push_front(a);
		}
		if (length > 0)
		{
			vector<int> listAwake;
			for (int i = 0; i < length; ++i)
			{
				if (directAwake[i] == ' ')
					break;
				listAwake.push_back(directAwake[i] - 'A');
				listArea[directAwake[i] - 'A'].isAwake = true;
			}
			while (true)
			{
				vector<int> newAwake;
				int size = listAwake.size();
				sizeArea -= size;
				for (int i = 0; i < size; ++i)
				{
					auto it = listArea[listAwake[i]].neighbor.cbegin();
					auto end = listArea[listAwake[i]].neighbor.cend();
					while (it != end)
					{
						if (listArea[*it].isAwake == false)
						{
							if (listArea[*it].awakeNeighbor == 2)
							{
								newAwake.push_back(*it);
								listArea[*it].isAwake = true;
							}
							else
								++listArea[*it].awakeNeighbor;
						}
						++it;
					}
				}
				if (newAwake.empty())
					break;
				++result;
				listAwake = newAwake;
			}
		}
		if (sizeArea > 0)
			cout << "THIS BRAIN NEVER WAKES UP\n";
		else
			cout << "WAKE UP IN, " << result << ", YEARS\n";
	}
	return 0;
}