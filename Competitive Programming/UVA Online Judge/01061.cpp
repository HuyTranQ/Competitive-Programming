#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;

string member[3];
vector<int> result;
int rhFactor;
vector<string> bloodType = {"A" , "B" , "AB" , "O"};
vector<vector<int>> childOutput = 
{
	{0 , 1 , 2 , 3},	//	0	A	B	AB	O
	{0 , 1 , 2},		//	1	A	B	AB
	{0 , 3},			//	2	A			O
	{1 , 3},			//	3		B		O
	{0 , 1},			//	4	A	B
	{3}					//	5				O
};
vector<vector<int>> parentCombination = 
{
	{2 , 0 , 1 , 2},	//	A
		{3 , 1 , 3},	//	B
			{1 , 4},	//	AB
				{5}		//	O
};
vector<vector<int>> childReverse =
{
	{0 , 1 , 2 , 4},	//	A
	{0 , 1 , 3 , 4},	//	B
	{0 , 1},			//	AB
	{0 , 2 , 3 , 5}		//	O
};
vector<string> rhCombination =
{
	"-",
	"+",
	"-+"
};

int indexAllele(string const & allele);
void findChild(int index[2]);
void findParent(int index[2]);
void printResult();

int main()
{
	int index[2];
	char a , b;
	for (int counter = 1;; ++counter)
	{
		cin >> member[0] >> member[1] >> member[2];
		if (member[0][0] == 'E')
			break;
		result.clear();
		cout << "Case " << counter << ": ";
		if (member[2][0] == '?')
		{
			index[0] = indexAllele(member[0]);
			index[1] = indexAllele(member[1]);
			findChild(index);
			a = member[0][member[0].length() - 1];
			b = member[1][member[1].length() - 1];
			rhFactor = (a == '-' && b == '-') ? 0 : 2;
		}
		else
		{
			index[1] = indexAllele(member[2]);
			b = member[2][member[2].length() - 1];
			if (member[0][0] == '?')
			{
				index[0] = indexAllele(member[1]);
				a = member[1][member[1].length() - 1];
			}
			else
			{
				index[0] = indexAllele(member[0]);
				a = member[0][member[0].length() - 1];
			}
			findParent(index);
			rhFactor = (a == '-' && b == '+') ? 1 : 2;
		}
		int i = 0;
		while (true)
		{
			if (member[i][0] == '?')
				printResult();
			else
				cout << member[i];
			++i;
			if (i == 3)
				break;
			cout << ' ';
		}
		cout << endl;
	}
	return 0;
}

void printResult()
{
	int size = result.size();
	int length = rhCombination[rhFactor].length();
	if (size == 0)
		cout << "IMPOSSIBLE";
	else if (size * length == 1)
		cout << bloodType[result[0]] << rhCombination[rhFactor][0];
	else
	{
		cout << "{";
		int i = 0 , j = 0;
		while (true)
		{
			cout << bloodType[result[i]] << rhCombination[rhFactor][j];
			++j;
			if (j == length)
			{
				j = 0;
				++i;
				if (i == size)
					break;
			}
			cout << ", ";
		}
		cout << "}";
	}
}

int indexAllele(string const & allele)
{
	if (allele.length() == 3)
		return 2;
	if (allele[0] == 'A')
		return 0;
	if (allele[0] == 'B')
		return 1;
	return 3;
}

void findChild(int index[2])
{
	if (index[0] > index[1])
	{
		int t = index[0];
		index[0] = index[1];
		index[1] = t;
	}
	result = childOutput[parentCombination[index[0]][index[1] - index[0]]];
}

void findParent(int index[2])
{
	int parent = index[0];
	int child = index[1];
	int limit = childReverse[child].size();
	vector<bool> check(4 , false);
	for (int i = 0; i < parent; ++i)
		for (int j = 0; j < limit; ++j)
			if (parentCombination[i][parent - i] == childReverse[child][j])
			{
				check[i] = true;
				break;
			}
	for (int i = parent; i < 4; ++i)
		for (int j = 0; j < limit; ++j)
			if (parentCombination[parent][i - parent] == childReverse[child][j])
			{
				check[i] = true;
				break;
			}
	for (int i = 0; i < 4; ++i)
		if (check[i] == true)
			result.push_back(i);
}