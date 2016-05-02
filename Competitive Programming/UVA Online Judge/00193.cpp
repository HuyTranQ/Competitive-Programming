#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::unordered_map;
using std::unordered_set;
using std::vector;

vector<int> max_result;
vector<int> result;
vector<int> black(101 , 0);
int graph_size , node_size , edge_size;

void graph_coloring(int node ,
					unordered_map<int , unordered_set<int>> & graph);

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> graph_size;
	max_result.reserve(100);
	result.reserve(100);
	for (; graph_size > 0; --graph_size)
	{
		unordered_map<int , unordered_set<int>> graph;

		cin >> node_size >> edge_size;
		for (; edge_size > 0; --edge_size)
		{
			int a , b;
			cin >> a >> b;
			graph[a].insert(b);
			graph[b].insert(a);
		}
		max_result.clear();
		result.clear();
		graph_coloring(1 , graph);
		cout << max_result.size() << '\n';
		for (int i = 0; ; ++i)
		{
			cout << max_result[i];
			if (i == max_result.size() - 1)
				break;
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}

void graph_coloring(int node , unordered_map<int , unordered_set<int>>& graph)
{
	if (node > node_size)
	{
		if (result.size() > max_result.size())
			max_result = result;
		return;
	}
	auto begin = graph[node].cbegin() , end = graph[node].cend();
	if (black[node] == 0)
	{
		result.push_back(node);
		for (auto it = begin; it != end; ++it)
			if ((*it) > node)
				--black[(*it)];
		graph_coloring(node + 1 , graph);
		for (auto it = begin; it != end; ++it)
			if ((*it) > node)
				++black[(*it)];
		result.pop_back();
	}
	graph_coloring(node + 1 , graph);
}