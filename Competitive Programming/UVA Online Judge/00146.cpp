#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::vector;
using std::swap;

struct Record
{
	char character;
	int position;
	Record(int character , int position) : character(character) , position(position)
	{

	}
};

string code;
int index , length;
vector<Record> track;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (true)
	{
		getline(cin , code);
		if (code[0] == '#')
			break;
		length = code.length();
		track.clear();
		track.push_back(Record(code[length - 1] , length - 1));
		for (index = length - 2; index >= 0; --index)
			if (code[index] < code[index + 1])
				break;
			else if (code[index] > code[index + 1])
				track.push_back(Record(code[index] , index));
		if (index == -1)
			cout << "No Successor";
		else
		{
			int limit;
			limit = track.size();
			int i;
			for (i = 0; i < limit; ++i)
				if (code[index] < track[i].character)
					break;
			swap(code[index] , code[track[i].position]);
			limit = (length - index) / 2;
			for (i = 1; i <= limit; ++i)
				swap(code[index + i] , code[length - i]);
			cout << code;
		}
		cout << '\n';
	}
	return 0;
}