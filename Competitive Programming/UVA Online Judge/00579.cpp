#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string timeInput;
int hour , minute , angleHour , angleMinute , angleDifference;

int main()
{
	cout.setf(std::ios::fixed , std::ios::floatfield);
	cout.precision(3);
	while (cin >> timeInput)
	{
		if (timeInput == "0:00")
			break;
		if (timeInput[1] == ':')
		{
			hour = timeInput[0] - '0';
			minute = (timeInput[2] - '0') * 10 + (timeInput[3] - '0');
		}
		else
		{
			hour = (timeInput[0] - '0') * 10 + (timeInput[1] - '0');
			minute = (timeInput[3] - '0') * 10 + (timeInput[4] - '0');
		}
		angleMinute = minute * 6 * 1000;
		angleHour = (hour % 12) * 5 * 6 * 1000 + (minute * 500);
		angleDifference = angleHour - angleMinute;
		if (angleDifference < 0)
			angleDifference = -angleDifference;
		if (angleDifference > 180000)
			angleDifference = 360000 - angleDifference;
		cout << (angleDifference / (double) 1000) << endl;
	}
	return 0;
}