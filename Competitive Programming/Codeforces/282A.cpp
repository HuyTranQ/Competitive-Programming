#include <iostream>

auto & input = std::cin;
auto & output = std::cout;

int main()
{
	std::ios::sync_with_stdio(false);
	int size;
	input >> size;
	int result = 0;
	for (; size > 0; --size)
	{
		char a , b , c;
		input >> a >> b >> c;
		if (a == '+' || c == '+')
			++result;
		else
			--result;
	}
	output << result;
	return 0;
}