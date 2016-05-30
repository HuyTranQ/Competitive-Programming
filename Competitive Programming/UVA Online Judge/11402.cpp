#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::getline;
const int MAX = 20;//1024000;

using byte = uint8_t;

int size , test , offset , update_left , update_right;
vector<string> string_(100 , "");
vector<byte> pirate_(MAX , 0);
vector<int> segment(MAX , 0);
vector<bool> integrity(MAX , false);

int build(int index , int left , int right);


int main()
{
	std::ios::sync_with_stdio(false);
	pirate_.reserve(MAX);
	string x(5 , '.');
	for (cin >> test; test > 0; --test)
	{
		int pattern;
		size = 0;
		for (cin >> pattern; pattern > 0; --pattern)
		{
			int repeat;
			cin >> repeat;
			cin.ignore();
			string line;
			getline(cin , line);
			auto begin = line.data();
			for (; repeat > 0; --repeat)
				for (auto it = begin; it != nullptr; ++it , ++size)
					pirate_[size] = *it;
		}

		build(0 , 0 , size);
		int query , counter = 0;
		for (cin >> query; query > 0; --query)
		{
			char c;
			int a , b;
			cin >> c >> a >> b;
			switch (c)
			{
				case 'F':
					for (int i = a; i <= b; ++i)
						pirate_[i] = 1;
					break;
				case 'E':
					for (int i = a; i <= b; ++i)
						pirate_[i] = 0;
					break;
				case 'I':
					for (int i = a; i <= b; ++i)
						pirate_[i] = (pirate_[i] == 0) ? 1 : 0;
					break;
				case 'S':
					break;
			}
		}
	}
	return 0;
}

int build(int index , int left , int right)
{
	if (left >= right)
		return 0;
	if (left + 1 == right)
		return pirate_[left];
	int child = 2 * index + 1;
	int mid = left + (right - left) / 2;
	segment[index] = build(child , left , mid) + build(child + 1 , mid , right);
	return segment[index];
}