#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::list;

struct Pair
{
	int a , b;
	Pair(int a , int b) : a(a) , b(b)
	{}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		list<Pair> result;
		for (int i = 1; ; ++i)
		{
			int b = n + i;
			int p = b * n;
			int a = p / i;
			if (a * i == p)
			{
				result.push_back(Pair(a , b));
				if (a == b)
					break;
			}
		}
		cout << result.size() << '\n';
		list<Pair>::iterator it = result.begin() , end = result.end();
		while (it != end)
		{
			cout << "1/" << n << " = " << "1/" << it->a << " + 1/" << it->b << '\n';
			++it;
		}
	}
	return 0;
}