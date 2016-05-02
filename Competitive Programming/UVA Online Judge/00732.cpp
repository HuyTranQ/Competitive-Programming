#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::string;
using std::list;
using std::getline;

struct Span
{
	int begin , end;
	char c;
};

string source , target , result , track;
int length , it , max, stackTop;

void findAnagram(int index,
				 int counter);

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (getline(cin , source))
	{
		getline(cin , target);
		cout << "[\n";
		if (source.length() == target.length())
		{
			length = source.length();
			max = 2 * length;
			it = 0;
			stackTop = -1;
			result.resize(max);
			track.resize(length);
			findAnagram(0 , 0);
		}
		cout << "]\n";
	}
	return 0;
}

void findAnagram(int index,
				 int counter)
{
	if (index == length)
	{
		int i = 0;
		while (true)
		{
			cout << result[i];
			++i;
			if (i == max)
				break;
			cout << ' ';
		}
		cout << '\n';
		return;
	}
	char c = target[index];
	for (int i = length - 1; i >= counter; --i)
		if (c == source[i])
		{
			int t = it , u = stackTop;
			for (int j = counter; j <= i; ++j)
			{
				++stackTop;
				track[stackTop] = source[j];
				result[it] = 'i';
				++it;
			}
			--stackTop;
			result[it] = 'o';
			++it;
			findAnagram(index + 1 , i + 1);
			it = t;
			stackTop = u;
		}
	if (stackTop == -1 ||
		track[stackTop] != c)
		return;
	char t = track[stackTop];
	--stackTop;
	result[it] = 'o';
	++it;
	findAnagram(index + 1 , counter);
	--it;
	++stackTop;
	track[stackTop] = t;
}