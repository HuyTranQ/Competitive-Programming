#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

size_t const MAX_SIZE = 100000;

int size , counter , query;
vector<int> frequency(MAX_SIZE , 0);
vector<int> offset(MAX_SIZE , 0);
vector<int> range(2 * MAX_SIZE , 0);

int build_range(int node , int left , int right);
int find_range(int position , int left , int right);
int max_range(int node , int left , int right , int range_left , int range_right);

int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> size && size > 0)
	{
		cin >> query;

		counter = -1;
		int current = MAX_SIZE + 1;
		for (int i = 0; i < size; ++i)
		{
			int t;
			cin >> t;
			if (current == t)
				++frequency[counter];
			else
			{
				++counter;
				offset[counter] = i;
				frequency[counter] = 1;
				current = t;
			}
		}
		++counter;

		build_range(0 , 0 , counter);

		for (; query > 0; --query)
		{
			int a , b;
			cin >> a >> b;
			--a; --b;
			int offset_a = find_range(a , 0 , counter);
			int offset_b = find_range(b , 0 , counter);
			if (offset_a == offset_b)
				cout << (b - a + 1);
			else
			{
				int max_left = offset[offset_a + 1] - a;
				int max_right = b - offset[offset_b] + 1;
				int max_tail = (max_left > max_right) ? max_left : max_right;
				if (offset_a + 1 == offset_b)
					cout << max_tail;
				else
				{
					int max_middle = max_range(0 , offset_a + 1 , offset_b , 0 , counter);
					cout << ((max_tail > max_middle) ? max_tail : max_middle);
				}
			}
			cout << '\n';
		}
	}
	return 0;
}

int build_range(int node , int left , int right)
{
	if (left >= right)
		return -1;
	if (right - left == 1)
	{
		range[node] = frequency[left];
		return frequency[left];
	}
	int mid = left + (right - left) / 2;
	int child = 2 * node + 1;
	range[node] = build_range(child , left , mid);
	++child;
	int max_right = build_range(child , mid , right);
	if (range[node] < max_right)
		range[node] = max_right;
	return range[node];
}

int find_range(int position , int left , int right)
{
	if (left >= right)
		return -1;
	if (right - left == 1)
		return left;
	int mid = left + (right - left) / 2;
	if (position == offset[mid])
		return mid;
	else if (position < offset[mid])
		return find_range(position , left , mid);
	else if (mid + 1 == counter || position < offset[mid + 1])
		return mid;
	else
		return find_range(position , mid + 1 , right);
}

int max_range(int node , int left , int right , int range_left , int range_right)
{
	if (range_left >= range_right ||
		left >= right ||
		left >= range_right ||
		right <= range_left)
		return -1;
	if (left == range_left &&
		right == range_right)
		return range[node];
	int mid = range_left + (range_right - range_left) / 2;
	int child = 2 * node + 1;
	if (left >= mid)
		return max_range(child + 1, left , right , mid , range_right);
	else if (right <= mid)
		return max_range(child , left , right , range_left , mid);

	int max_left = max_range(child , left , mid , range_left , mid);
	++child;
	int max_right = max_range(child , mid , right , mid , range_right);
	if (max_left < max_right)
		return max_right;
	else
		return max_left;
}