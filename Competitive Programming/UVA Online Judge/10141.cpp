#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

int main()
{
	int sizeRequirement , sizeRequest , sizeProposal , counter , compliance;
	double currentPrice , price;
	string line , name , currentName;
	vector<string> result;
	counter = 1;
	while (true)
	{	
		cin >> sizeRequirement >> sizeRequest;
		if (sizeRequirement == 0)
			break;
		cin.ignore();
		compliance = 0;
		currentPrice = 0;
		for (int i = 0; i < sizeRequirement; ++i)
			getline(cin , line);
		for (int i = 0; i < sizeRequest; ++i)
		{
			getline(cin , name);
			cin >> price >> sizeProposal;
			cin.ignore();
			for (int j = 0; j < sizeProposal; ++j)
				getline(cin , line);
			if (sizeProposal > compliance ||
				sizeProposal == compliance &&
				price < currentPrice)
			{
				compliance = sizeProposal;
				currentPrice = price;
				currentName = name;
			}
		}
		result.push_back(currentName);
		++counter;
	}
	int sizeResult = result.size();
	for (int i = 1; i <= sizeResult; ++i)
	{
		cout << "RFP #" << i << endl;
		cout << result[i - 1] << endl;
		if (i != sizeResult)
			cout << endl;
	}
	return 0;
}