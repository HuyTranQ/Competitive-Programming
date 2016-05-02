#include <iostream>
#include <queue>
#include <stack>

using std::cin;
using std::cout;
using std::stack;
using std::queue;
using std::priority_queue;

int size;
bool isStack , isQueue , isPriority;
char * output[] =
{
	"impossible",
	"stack",
	"queue",
	"priority queue",
	"not sure",
};
int result[] = {0 , 1 , 2 , 4 , 3 , 4 , 4 , 4};

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> size)
	{
		stack<int> dataStack;
		queue<int> dataQueue;
		priority_queue<int> dataPriority;
		isStack = isQueue = isPriority = true;
		while (size > 0)
		{
			int operation , value;
			cin >> operation >> value;
			if (operation == 1)
			{
				if (isStack)
					dataStack.push(value);
				if (isQueue)
					dataQueue.push(value);
				if (isPriority)
					dataPriority.push(value);
			}
			else
			{
				if (isStack)
					if (dataStack.empty() ||
						dataStack.top() != value)
						isStack = false;
					else
						dataStack.pop();
				if (isQueue)
					if (dataQueue.empty() ||
						dataQueue.front() != value)
						isQueue = false;
					else
						dataQueue.pop();
				if (isPriority)
					if (dataPriority.empty() ||
						dataPriority.top() != value)
						isPriority = false;
					else
						dataPriority.pop();
			}
			--size;
		}
		int sum = 0;
		sum += (isStack) ? 1 : 0;
		sum += (isQueue) ? 2 : 0;
		sum += (isPriority) ? 4 : 0;
		cout << output[result[sum]] << '\n';
	}
	return 0;
}