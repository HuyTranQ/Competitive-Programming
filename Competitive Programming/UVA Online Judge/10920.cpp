#include <iostream>

using std::cin;
using std::cout;

long long size , position , row , col , shell, outside , inside , offset;

long long findShell(long long value , 
			  long long begin , 
			  long long end);

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> size >> position)
	{
		if (size == 0)
			break;
		if (position == 1)
			row = col = (size / 2) + 1;
		else
		{
			shell = findShell(position , 1 , size + 1);
			offset = (size - shell) / 2;
			outside = shell * shell;
			outside -= shell - 1;
			if (position > outside)
			{
				col = shell;
				row = 1 + position - outside;
			}
			else
			{
				outside -= shell - 1;
				if (position > outside)
				{
					row = 1;
					col = 1 + position - outside;
				}
				else
				{
					outside -= shell - 1;
					if (position > outside)
					{
						col = 1;
						row = shell - position + outside;
					}
					else
					{
						row = shell;
						col = outside - position + 1;
					}
				}
			}
			row += offset;
			col += offset;
		}
		cout << "Line = " << row << ", column = " << col << ".\n";
	}
	return 0;
}

long long findShell(long long value ,
			  long long begin ,
			  long long end)
{
	long long mid = (begin + end) / 2;
	mid += (mid % 2 == 0);
	if (value > mid * mid)
		return findShell(value , mid , end);
	mid -= 2;
	if (value > mid * mid)
		return mid + 2;
	return findShell(value , begin , mid);
}