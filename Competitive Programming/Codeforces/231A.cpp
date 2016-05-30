#include <iostream>

auto & input = std::cin;
auto & output = std::cout;

int main()
{
	std::ios::sync_with_stdio(false);
	int size;
	input >> size;
	size_t result = 0;
	for (; size > 0; --size)
	{
		int a , b , c;
		input >> a >> b >> c;
		int sure = a + b + c;
		if (sure >= 2)
			++result;
	}
	output << result;
	return 0;
}