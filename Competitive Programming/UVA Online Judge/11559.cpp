#include <iostream>
#include <climits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	int sizeParticipant , limit , sizeHotel , sizeWeek , sizeBed;
	int minPrice , price;
	bool  chosen;
	
	while (cin >> sizeParticipant)
	{
		cin >> limit >> sizeHotel >> sizeWeek;
		chosen = false;
		for (int i = 0; i < sizeHotel; ++i)
		{	
			cin >> price;
			int j = 0;
			for (; j < sizeWeek; ++j)
			{
				cin >> sizeBed;
				if (sizeBed >= sizeParticipant)
					break;
			}
			if (j < sizeWeek)
			{
				price *= sizeParticipant;
				if (price <= limit)
				{
					limit = price;
					chosen = true;
				}
				for (++j; j < sizeWeek; ++j)
					cin >> sizeBed;
			}
		}
		if (chosen)
			cout << limit;
		else
			cout << "stay home";
		cout << endl;
	}
	return 0;
}