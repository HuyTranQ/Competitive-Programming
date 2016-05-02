#include <iostream>
#include <map>
#include <forward_list>
#include <unordered_set>
#include <string>

using std::cin;
using std::cout;
using std::map;
using std::forward_list;
using std::unordered_set;
using std::string;
using std::getline;

int testCase;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin >> testCase;
	for (cin.ignore(); testCase > 0; --testCase)
	{
		int acorn = 0 , tree = 0;
		forward_list<int> data[26];
		string line;
		unordered_set<int> vertex;
		while (getline(cin , line) &&
			   line[0] != '*')
		{
			int source = line[1] - 'A' , target = line[3] - 'A';
			data[source].push_front(target);
			data[target].push_front(source);
		}
		getline(cin , line);
		int length = line.length();
		for (int i = 0; i < length; i += 2)
			vertex.insert(line[i] - 'A');
		while (!vertex.empty())
		{
			int root = (*vertex.begin());
			if (data[root].empty())
			{
				++acorn;
				vertex.erase(root);
			}
			else
			{
				++tree;
				forward_list<int> neighbor;
				neighbor.push_front(root);
				do
				{
					int node = (*neighbor.begin());
					neighbor.pop_front();
					vertex.erase(node);
					forward_list<int>::iterator it = data[node].begin() , end = data[node].end();
					while (it != end)
					{
						if (vertex.find(*it) != vertex.end())
							neighbor.push_front((*it));
						++it;
					}
				} while (!neighbor.empty());
			}
		}
		cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
	}
	return 0;
}