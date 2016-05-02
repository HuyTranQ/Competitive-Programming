#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::multiset;
using std::advance;

multiset<unsigned> listNumber;
multiset<unsigned>::iterator it;
unsigned number , size;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> number)
	{
		listNumber.insert(number);
		it = listNumber.begin();
		size = listNumber.size();
		advance(it , size / 2 + size % 2 - 1);
		if (size % 2 == 1)
			cout << (*it);
		else
		{
			unsigned t = (*it);
			++it;
			cout << (t + (*it)) / 2;
		}
		cout << '\n';
	}
	return 0;
}