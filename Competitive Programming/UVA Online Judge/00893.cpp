#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int day , month , year;
int yearCycle[4] = {146097 , 36524 , 1461};
int yearUnit[4] = { 400 , 100 , 4};
int monthShift[12] = {0 , 31 , 61 , 92 , 122 , 153 , 184 , 214 , 245 , 275 , 306 , 337};
int addDays;

bool isLeap(int year);

int main()
{
	bool x;
	while (true)
	{
		cin >> addDays >> day >> month >> year;
		if (day == 0)
			break;
		if (month > 2 && isLeap(year) ||
			month <= 2 && isLeap(year - 1))
			++addDays;
		month = (month + 9) % 12;
		year -= 1 + (month >= 10);
		addDays += year * 365 + year / 4 - year / 100 + year / 400 + monthShift[month] + day;
		year = 1;
		for (int i = 0; i < 3; ++i)
		{
			year += yearUnit[i] * (addDays / yearCycle[i]);
			addDays %= yearCycle[i];
			if (addDays == 0)
			{
				month = 2;
				if (i == 0 || i == 2)
					day = 28;
				else
					day = 27;
				--year;
				break;
			}
		}
		if (addDays != 0)
		{
			int t = addDays / 365;
			if (t == 3 && isLeap(year + t))
				if (addDays <= 1096)
					t = 2;
				else
					--addDays;
			year += t;
			addDays -= t * 365;
			if (addDays == 0)
			{
				month = 2;
				day = 28 + isLeap(year);
				--year;
			}
			else	
				for (int i = 11; i >= 0; --i)
					if (addDays > monthShift[i])
					{
						month = (i + 2) % 12 + 1;
						day = addDays - monthShift[i];
						break;
					}
		}
		if (month <= 2)
			++year;
		cout << day << ' ' << month << ' ' << year << endl;
	}
	return 0;
}

bool isLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 ||
		year % 400 == 0)
		return true;
	return false;
}