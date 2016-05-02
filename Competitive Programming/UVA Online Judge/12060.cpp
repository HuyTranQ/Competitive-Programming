#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::right;

int total , sum , number , a , b, span , indent;
bool isNegative;

int gcd(int x , int y);
int digits(int x);

int main()
{
	for (int counter = 1; ; ++counter)
	{
		cin >> total;
		if (total == 0)
			break;
		sum = 0;
		isNegative = false;
		for (int i = 0; i < total; ++i)
		{
			cin >> number;
			sum += number;
		}
		if (sum < 0)
		{
			isNegative = true;
			sum = -sum;
		}
		a = sum / total;
		b = sum % total;
		cout << "Case " << counter << ":\n";
		if (b == 0)
			cout << (isNegative ? "- " : "") << a << endl;
		else
		{
			int t = gcd(b , total);
			b /= t;
			total /= t;
			int lb = digits(b);
			int lc = digits(total);
			span = (lb > lc) ? lb : lc;
			int la = (isNegative ? 2 : 0) + ((a == 0) ? 0 : digits(a));
			cout << setw(la + span) << right << b << endl;
			cout << (isNegative ? "- " : "");
			if (a != 0)
				cout << a;
			cout << string(span , '-') << endl;
			cout << setw(la + span) << right << total << endl;
		}
	}
	return 0;
}

int gcd(int x , int y)
{
	int t;
	while (y != 0)
	{
		t = y;
		y = x % y;
		x = t;
	}
	return x;
}

int digits(int x)
{
	int result = 0;
	while (x > 0)
	{
		x /= 10;
		++result;
	}
	return result;
}