#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::sort;
using std::string;
using std::vector;
using std::unordered_set;

struct Element
{
	string origin , edited;
	Element()
	{

	}
	Element(string const & origin ,
			string const & edited) : origin(origin) , edited(edited)
	{
		
	}
};

string word , origin;
vector<Element> dictionary;
unordered_set<string> rawDictionary, duplicate;

void InsertionSort(string & text);
void LowerString(string & text);
bool CompareElement(Element const & a ,
					Element const & b);

int main()
{
	while (true)
	{
		cin >> word;
		if (word == "#")
			break;
		origin = word;
		LowerString(word);
		InsertionSort(word);
		dictionary.push_back(Element(origin , word));
		if (rawDictionary.find(word) == rawDictionary.end())
			rawDictionary.insert(word);
		else if (duplicate.find(word) == duplicate.end())
			duplicate.insert(word);
	}
	sort(dictionary.begin() , dictionary.end() , CompareElement);
	int size = dictionary.size();
	for (int i = 0; i < size; ++i)
	{
		if (duplicate.find(dictionary[i].edited) == duplicate.end())
			cout << dictionary[i].origin << endl;
	}
		
	return 0;
}

void InsertionSort(string & text)
{
	int length = text.length() , j;
	char current;
	for (int i = 1; i < length; ++i)
	{
		current = text[i];
		j = i;
		while (j > 0 && current < text[j - 1])
		{
			text[j] = text[j - 1];
			--j;
		}
		text[j] = current;
	}
}

void LowerString(string & text)
{
	int length = text.length();
	for (int i = 0; i < length; ++i)
		text[i] = tolower(text[i]);
}

bool CompareElement(Element const & a ,
					Element const & b)
{
	return (a.origin < b.origin);
}