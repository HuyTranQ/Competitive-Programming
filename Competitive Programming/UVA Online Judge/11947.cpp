#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int testCase , day , month , year , daysOffset , sign , oldMonth;
string startDate;

string zodiacSign[] =
{
	"aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"
};

int zodiacBegin[] = 
{ 21 , 20 , 21 , 21 , 22 , 22 , 23 , 22 , 24 , 24 , 23 , 23 };

int monthShift[12] = 
{ 0 , 31 , 61 , 92 , 122 , 153 , 184 , 214 , 245 , 275 , 306 , 337 };

bool isLeap(int year);

int main()
{
	cin >> testCase;
	for (int counter = 1; counter <= testCase; ++counter)
	{
		cin >> startDate;
		month = (startDate[0] - '0') * 10 + (startDate[1] - '0');
		day = (startDate[2] - '0') * 10 + (startDate[3] - '0');
		year = 0;
		int length = startDate.length();
		for (int i = 4; i < length; ++i)
			year = year * 10 + (startDate[i] - '0');
		oldMonth = month;
		month = (month + 9) % 12;
		daysOffset = monthShift[month] + day;
		daysOffset += 280;
		int t = isLeap(year + (month < 10));
		if (daysOffset > 365 + t)
			daysOffset -= 365 + t;
		for (int i = 11; i >= 0; --i)
			if (daysOffset > monthShift[i])
			{
				month = (i + 2) % 12;
				day = daysOffset - monthShift[i];
				break;
			}
		if (day >= zodiacBegin[month])
			sign = month;
		else
			sign = (month + 11) % 12;
		++month;
		if (oldMonth > month)
			++year;
		cout << counter << ' ';
		if (month < 10)
			cout << '0';
		cout << month << '/';
		if (day < 10)
			cout << '0';
		cout << day << '/' << year << ' ' << zodiacSign[sign] << endl;
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