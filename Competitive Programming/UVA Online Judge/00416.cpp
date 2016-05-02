#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::vector;
using std::unordered_multimap;
using std::equal_range;

using byte = std::uint8_t;

byte to_byte(string const & diode);
void generate_sequence(int index ,
				   int burn ,
				   byte & mask);

void turn_on_bit(byte & number ,
				 byte offset);
void turn_off_bit(byte & number ,
				  byte offset);
bool check_order(int index , int number , byte mask);
bool is_compatable(byte a , byte b);

byte const DEFAULT_MASK = to_byte("YYYYYYY");
byte const END_SEQUENCE = 127;
byte const original[] = {
	to_byte("YYYYYYN"),
	to_byte("NYYNNNN"),
	to_byte("YYNYYNY"),
	to_byte("YYYYNNY"),
	to_byte("NYYNNYY"),
	to_byte("YNYYNYY"),
	to_byte("YNYYYYY"),
	to_byte("YYYNNNN"),
	to_byte("YYYYYYY"),
	to_byte("YYYYNYY")
};

int length;
vector<unordered_multimap<byte , byte>> data(10);
vector<byte> sequence;

int main()
{
	std::ios::sync_with_stdio(false);
	for (int i = 0; i <= 7; ++i)
	{
		byte t = DEFAULT_MASK;
		generate_sequence(0 , i , t);
	}
	sequence.reserve(12);
	while (cin >> length && length > 0)
	{
		sequence.clear();
		cin.ignore();
		for (int i = 0; i < length; ++i)
		{
			string line;
			getline(cin , line);
			sequence.push_back(to_byte(line));
		}
		bool match = false;
		for (int i = 10; i >= length; --i)
		{
			match = check_order(0 , i - 1 , byte(DEFAULT_MASK));
			if (match)
				break;
		}
		cout << ((match) ? "MATCH" : "MISMATCH") << '\n';
	}
	return 0;
}


void generate_sequence(int index , int burn , byte & mask)
{
	if (burn > 10 - index)
		return;

	if (index == 10)
	{
		for (byte i = 0; i <= 9; ++i)
			data[i].insert({ original[i] & mask , mask });
		return;
	}

	if (burn > 0)
	{
		turn_off_bit(mask , index);
		generate_sequence(index + 1 , burn - 1 , mask);
		turn_on_bit(mask , index);
	}

	generate_sequence(index + 1 , burn , mask);
}

bool check_order(int index , int number , byte mask)
{
	if (index == sequence.size())
		return true;
	byte current = sequence[index];
	auto mask_list = data[number].equal_range(current);
	for (auto it = mask_list.first , endit = mask_list.second; it != endit; ++it)
	{
		if (is_compatable(mask , it->second))
		{
			if (check_order(index + 1 , number - 1 , it->second))
				return true;
		}
	}
		
	return false;
}

byte to_byte(string const & diode)
{
	byte result = 0;
	for (int i = 0; i < 7; ++i)
		if (diode[i] == 'Y')
			turn_on_bit(result , i);
	return result;
}

void turn_on_bit(byte & number , byte offset)
{
	number |= 1 << offset;
}

void turn_off_bit(byte & number , byte offset)
{
	number &= ~(1 << offset);
}

bool is_compatable(byte a , byte b)
{
	return (b == (a & b));
}