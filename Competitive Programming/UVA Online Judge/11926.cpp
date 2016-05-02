#include <iostream>

using std::cin;
using std::cout;

const int maxTime = 15625;
const int typeSize = 8 * sizeof(unsigned long long);

unsigned long long timeline[maxTime];
unsigned long long touchSignal , oneSignal;
int start , finish , interval , cycle , input[2];
int offset , begin , end , middle;
bool overlap;

bool isOverlapped();

int main()
{
	std::ios_base::sync_with_stdio(false);
	oneSignal = -1;
	touchSignal = 1;
	touchSignal <<= 63;
	while (cin >> input[0] >> input[1])
	{
		if (input[0] == 0 && input[1] == 0)
			break;
		for (int i = 0; i < maxTime; ++i)
			timeline[i] = 0;
		overlap = false;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < input[i]; ++j)
			{
				cin >> start >> finish;
				if (i == 1)
					cin >> cycle;
				if (!overlap)
				{
					interval = finish - start;
					while (true)
					{
						offset = start % typeSize;
						begin = start / typeSize;
						if (begin >= maxTime)
							break;
						end = finish / typeSize;
						if (end >= maxTime)
						{
							if (end != maxTime ||
								finish % typeSize != 0)
							{
								end = maxTime - 1;
								finish = typeSize * maxTime;
								interval = finish - start;
							}
						}
						if (begin == end)
						{
							int t = typeSize - (offset + interval);
							unsigned long long bits = timeline[begin] >> t;
							bits <<= (t + offset);
							if (bits != 0)
							{
								overlap = true;
								break;
							}
							else
							{
								bits = (oneSignal << (offset + t));
								bits >>= offset;
								timeline[begin] |= bits;
							}
						}
						else
						{
							middle = end - begin - 1;
							if (isOverlapped())
							{
								overlap = true;
								break;
							}
						}
						if (i == 0)
							break;
						else
						{
							start += cycle;
							finish += cycle;
						}
					}
				}
			}
		cout << ((overlap) ? "CONFLICT" : "NO CONFLICT") << '\n';
	}
	return 0;
}

bool isOverlapped()
{
	unsigned long long bits;
	//	Head
	bits = timeline[begin] << offset;
	if (bits != 0)
		return true;
	bits = (oneSignal << offset);
	bits >>= offset;
	timeline[begin] |= bits;
	//	Middle
	for (int i = 1; i <= middle; ++i)
	{
		if (timeline[begin + i] != 0)
			return true;
		timeline[begin + i] = -1;
	}
	//	Tail
	int tail = finish % typeSize;
	if (tail > 0)
	{
		bits = timeline[end] >> (typeSize - tail);
		if (bits != 0)
			return true;
		bits = ((oneSignal << (typeSize - tail)));
		timeline[end] |= bits;
	}
	return false;
}