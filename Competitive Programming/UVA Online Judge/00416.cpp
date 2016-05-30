#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::vector;

using byte = std::uint8_t;

byte reverse(string const & binary);
//string to_string(byte input);


vector<byte> const original = {
	reverse("YYYYYYN") ,
	reverse("NYYNNNN") ,
	reverse("YYNYYNY") ,
	reverse("YYYYNNY") ,
	reverse("NYYNNYY") ,
	reverse("YNYYNYY") ,
	reverse("YNYYYYY") ,
	reverse("YYYNNNN") ,
	reverse("YYYYYYY") ,
	reverse("YYYYNYY")
};

int size;
vector<byte> sequence;

int main()
{
	std::ios::sync_with_stdio(false);
	sequence.reserve(10);
	while (cin >> size && size > 0)
	{
		cin.ignore();
		sequence.clear();
		for (int i = 0; i < size; ++i)
		{
			string line;
			getline(cin , line);
			sequence.push_back(reverse(line));
		}

		bool is_sequence = false;
		for (int i = 9; i >= size - 1; --i)
		{
			byte defect = 127;
			//string _defect = to_string(defect);
			int j = i;
			for (; j >= i - size + 1; --j)
			{
				//string _original = to_string(original[j]);
				//string _sequence = to_string(sequence[i - j]);
				if ((original[j] | sequence[i - j]) != original[j])
					break;
				if ((original[j] & sequence[i - j]) != sequence[i - j])
					break;
				//byte new_defect = ~(original[j] ^ sequence[i - j]) & 127;
				//string _new_defect = to_string(new_defect);
				defect &= ~(original[j] ^ sequence[i - j]) & 127;
				//_defect = to_string(defect);
			}
			if (j < i - size + 1)
			{
				is_sequence = true;
				break;
			}
		}
		if (!is_sequence)
			cout << "MIS";
		cout << "MATCH\n";
	}
	return 0;
}
//
//std::string to_string(byte input)
//{
//	int size = 8;
//	string result(size , 'N');
//	for (--size; size >= 0; --size)
//		if (((1 << size) & input) != 0)
//			result[size] = 'Y';
//	return result;
//}

byte reverse(string const & binary)
{
	byte result = 0;
	size_t length = binary.length();
	for (size_t i = 0; i < length; ++i)
		if (binary[i] == 'Y')
			result |= 1 << i;
	return result;
}