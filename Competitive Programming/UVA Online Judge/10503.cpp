#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int spaces , pieces;
vector<int> domino[7];
int start , finish;
bool play_domino(int current ,
				 int end ,
				 int space ,
				 vector<vector<short>> & check);

int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> spaces &&
		   spaces > 0)
	{
		vector<vector<short>> check(7 , vector<short>(7 , 0));
		cin >> pieces;
		int t;
		cin >> t >> start >> finish >> t;
		for (int i = 0; i < pieces; ++i)
		{
			int a , b;
			cin >> a >> b;
			domino[a].push_back(b);
			++check[a][b];
			++check[b][a];
			if (b != a)
				domino[b].push_back(a);
		}
		if (play_domino(start , finish , spaces , check))
			cout << "YES\n";
		else
			cout << "NO\n";
		for (int i = 0; i <= 6; ++i)
			domino[i].clear();
	}
	return 0;
}

bool play_domino(int current , int end , int space ,
				 vector<vector<short>> & check)
{
	if (space == 0)
		return current == end;
	vector<int> & next = domino[current];
	size_t size = next.size();
	for (int i = 0; i < size; ++i)
		if (check[current][next[i]] > 0)
		{
			--check[current][next[i]];
			--check[next[i]][current];
			bool solution = play_domino(next[i] , end , space - 1 , check);
			++check[current][next[i]];
			++check[next[i]][current];
			if (solution)
				return true;
		}
	return false;
}