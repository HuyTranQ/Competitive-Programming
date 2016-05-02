#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	double height , distanceDrop, distanceDay , distanceNight , fatigue , currentHeight;
	int day;
	while (true)
	{
		cin >> height >> distanceDay >> distanceNight >> fatigue;
		if (height == 0)
			break;
		distanceDrop = distanceDay * (fatigue / 100);
		currentHeight = 0;
		for (int day = 1; ; ++day)
		{
			if (distanceDay > 0)
				currentHeight += distanceDay;
			if (currentHeight > height)
			{
				cout << "success on day " << day << endl;
				break;
			}
			currentHeight -= distanceNight;
			distanceDay -= distanceDrop;
			if (currentHeight < 0)
			{
				cout << "failure on day " << day << endl;
				break;
			}
		}
	}
	return 0;
}