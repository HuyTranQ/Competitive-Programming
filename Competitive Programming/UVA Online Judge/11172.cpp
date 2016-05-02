#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	long long a , b;
	int t;
	cin >> t;
	while (t > 0)
	{
		cin >> a >> b;
		if (a < b)
			cout << '<' << endl;
		else if (a > b)
			cout << '>' << endl;
		else
			cout << '=' << endl;
		--t;
	}
	return 0;
}