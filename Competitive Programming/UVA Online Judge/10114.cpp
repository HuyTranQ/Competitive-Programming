#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Loan
{
	int duration , depSize;
	float payment , amount;
};

struct Record
{
	int month;
	float rate;
};

int main()
{
	Loan loan;
	vector<Record> record;
	double carValue , rate , payment;
	int month , counter;
	while (true)
	{
		cin >> loan.duration >> loan.payment >> loan.amount >> loan.depSize;
		if (loan.duration < 0)
			break;
		record.resize(loan.depSize);
		for (int i = 0; i < loan.depSize; ++i)
			cin >> record[i].month >> record[i].rate;
		rate = 1 - record[0].rate;
		carValue = (loan.amount + loan.payment) * rate;
		payment = loan.amount / loan.duration;
		month = 0;
		counter = 1;
		while (true)
		{
			if (carValue > loan.amount ||
				month == loan.duration)
			{
				cout << month << " month" << ((month == 1) ? "" : "s") << endl;
				break;
			}
			++month;
			if (counter < loan.depSize &&
				month == record[counter].month)
			{
				rate = 1 - record[counter].rate;
				++counter;
			}
			loan.amount -= payment;
			carValue *= rate;
		}
	}
	return 0;
}