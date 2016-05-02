#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int testSize;
	cin >> testSize;

	int big1 , big2;
	int salary[3];

	for (int i = 1; i <= testSize; ++i)
	{
		cin >> salary[0] >> salary[1] >> salary[2];
		cout << "Case " << i << ": ";
		if (salary[0] > salary[1])
		{
			if (salary[0] < salary[2])
				cout << salary[0];
			else
				cout << ((salary[2] < salary[1]) ? salary[1] : salary[2]);
		}
		else
		{
			if (salary[1] < salary[2])
				cout << salary[1];
			else
				cout << ((salary[2] < salary[0]) ? salary[0] : salary[2]);
		}
		cout << endl;
	}
	return 0;
}