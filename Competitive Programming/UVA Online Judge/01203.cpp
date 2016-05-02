#include <iostream>
#include <vector>
#include <queue>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::priority_queue;

struct Register
{
	int id , time;
	Register(int id , int time) : id(id) , time(time)
	{}
};

struct RegisterCompare
{
	bool operator() (Register const & r1 ,
					 Register const & r2);
};

priority_queue<Register , vector<Register> , RegisterCompare> stream;
vector<int> query(3001);
string signal;
int sizeTransaction;

int main()
{
	std::ios_base::sync_with_stdio(false);
	while (cin >> signal &&
		   signal[0] == 'R')
	{
		int id , period;
		cin >> id >> period;
		query[id] = period;
		stream.push(Register(id , period));
	}
	cin >> sizeTransaction;
	while (sizeTransaction > 0)
	{
		Register transaction = stream.top();
		cout << transaction.id << '\n';
		stream.pop();
		stream.push(Register(transaction.id , query[transaction.id] + transaction.time));
		--sizeTransaction;
	}
	return 0;
}

bool RegisterCompare::operator() (Register const & r1 ,
								  Register const & r2)
{
	if (r1.time > r2.time)
		return true;
	else if (r1.time < r2.time)
		return false;
	else if (r1.id > r2.id)
		return true;
	else
		return false;
}