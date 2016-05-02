#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<bool> isPrime = {
	false , false , true , true ,
	false , true , false , true ,
	false , false , false , true ,
	false , true , false , false ,
	false , true , false , true ,
	false , false , false , true ,
	false , false , false , false ,
	false , true , false , true
};
vector<bool> check(17 , true);
vector<int> result(16);
int size , counter;

void generate(int index);

int main()
{
	std::ios::sync_with_stdio(false);
	result[0] = 1;
	counter = 1;
	while (cin >> size)
	{
		if (counter != 1)
			cout << '\n';
		cout << "Case " << counter << ":\n";
		generate(1);
		++counter;
	}
	return 0;
}

void generate(int index)
{
	if (index == size)
	{
		if (!isPrime[result[index - 1] + 1])
			return;
		int i = 0;
		while (true)
		{
			cout << result[i];
			++i;
			if (i == size)
				break;
			cout << ' ';
		}
		cout << '\n';
		return;
	}
	int begin = 2 + (index + 1) % 2;
	int previous = result[index - 1];
	while (begin <= size)
	{
		if (check[begin] &&
			isPrime[begin + previous])
		{
			check[begin] = false;
			result[index] = begin;
			generate(index + 1);
			check[begin] = true;
		}
		begin += 2;
	}
}