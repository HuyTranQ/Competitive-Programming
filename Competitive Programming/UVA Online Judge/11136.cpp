#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::map;

struct Bill
{
	long long frequency;
	Bill() : frequency(0)
	{}
};

int	sizePromotion , sizeBill;
map<long long , Bill> urn;

int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> sizePromotion && sizePromotion > 0)
	{
		long long total = 0;
		map<long long , Bill>::iterator min;
		map<long long , Bill>::reverse_iterator max;
		for (int i = 0; i < sizePromotion; ++i)
		{
			cin >> sizeBill;
			while (sizeBill > 0)
			{
				long long t;
				cin >> t;
				++urn[t].frequency;
				--sizeBill;
			}
			min = urn.begin();
			max = urn.rbegin();
			total += max->first - min->first;
			if (min->second.frequency == 1)
				urn.erase(min);
			else
				--min->second.frequency;
			if (max->second.frequency == 1)
				urn.erase((++max).base());
			else
				--max->second.frequency;
		}
		cout << total << '\n';
		urn.clear();
	}
	return 0;
}