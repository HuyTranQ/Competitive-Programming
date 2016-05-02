#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

int toValue();

int totalRecord , length , entry , oldValue , currentValue , consecutive;
vector<string> record;

int main()
{
	for (int counter = 1; cin >> totalRecord; ++counter)
	{
		if (totalRecord == 0)
			break;
		record.clear();
		record.resize(totalRecord);
		cin.ignore();
		for (int i = 0; i < totalRecord; ++i)
			getline(cin , record[i]);
		cout << "Case " << counter << ":\n";
		length = record[0].length();
		cout << record[0];
		entry = 0;
		currentValue = toValue();
		entry = 1;
		while (true)
		{
			consecutive = 0;
			while (entry < totalRecord)
			{
				oldValue = currentValue;
				currentValue = toValue();
				if (currentValue - oldValue > 1)
					break;
				++consecutive;
				++entry;
			} 
			if (consecutive > 0)
				for (int i = 0; i < length; ++i)
					if (record[entry - consecutive - 1][i] != record[entry - 1][i])
					{
						cout << "-" << record[entry - 1].substr(i);
						break;
					}
			cout << endl;
			if (entry >= totalRecord)
				break;
			cout << record[entry];
			++entry;
		}
		cout << endl;
	}
	return 0;
}

int toValue()
{
	int result = 0;
	for (int i = 0; i < length; ++i)
		result = result * 10 + (record[entry][i] - '0');
	return result;
}