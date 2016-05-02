#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct Soldier
{
	int left , right;
};

vector<Soldier> buddy;
Soldier span;
int soldier , report;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (true)
	{
		cin >> soldier >> report;
		if (report == 0)
			break;
		buddy.clear();
		buddy.resize(soldier + 1);
		for (int i = 1; i <= soldier; ++i)
		{
			buddy[i].left = i - 1;
			buddy[i].right = i + 1;
		}
		buddy[1].left = -1;
		buddy[soldier].right = -1;
		for (; report > 0; --report)
		{
			cin >> span.left >> span.right;
			if (buddy[span.left].left != -1)
			{
				cout << buddy[span.left].left;
				buddy[buddy[span.left].left].right = buddy[span.right].right;
			}
			else
				cout << '*';
			cout << ' ';
			if (buddy[span.right].right != -1)
			{
				cout << buddy[span.right].right;
				buddy[buddy[span.right].right].left = buddy[span.left].left;
			}
			else
				cout << '*';
			cout << '\n';
		}
		cout << "-\n";
	}
	return 0;
}