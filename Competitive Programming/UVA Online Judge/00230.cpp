#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
using std::string;
using std::getline;

class Book
{
public:
	string author , title;
	Book(string const && author ,
		 string const && title) :
		author(author),
		title(title)
	{

	}
	Book(string const & author ,
		 string const & title) :
		author(author) ,
		title(title)
	{

	}
};

bool compareBook(Book const & book1 ,
				 Book const & book2);
string getTitle(string const & raw);
string getAuthor(string const & raw);
int getPosition(vector<Book> const & listBook ,
				string const & title);

int main()
{
	vector<Book> listBook;
	vector<bool> listBorrowed;
	vector<int> listReturned;
	string line;
	char pre;
	while (true)
	{
		getline(cin , line);
		if (line[0] == 'E')
			break;
		listBook.push_back(Book(getAuthor(line) , getTitle(line)));
	}
	sort(listBook.begin() , listBook.end() , compareBook);
	for (int i = 0; i < listBook.size(); ++i)
		cout << listBook[i].title << endl;
	listBorrowed.resize(listBook.size() , false);
	while (true)
	{
		getline(cin , line);
		pre = line[0];
		if (pre == 'E')
			break;
		switch (pre)
		{
			case 'B':
				listBorrowed[getPosition(listBook , getTitle(line))] = true;
				break;
			case 'R':
				listReturned.push_back(getPosition(listBook , getTitle(line)));
				break;
			case 'S':
				sort(listReturned.begin() , listReturned.end());
				int size = listReturned.size();
				int position;
				for (int i = 0; i < size; ++i)
				{
					position = listReturned[i];
					listBorrowed[position] = false;
					cout << "Put \"" << listBook[position].title << "\" ";
					int j = position - 1;
					while (j >= 0)
					{
						if (listBorrowed[j] == false)
							break;
						--j;
					}
					if (j == -1)
						cout << "first";
					else
						cout << "after \"" << listBook[j].title << "\"";
					cout << endl;
				}
				cout << "END" << endl;
				listReturned.resize(0);
				break;
		}
	}
	return 0;
}

bool compareBook(Book const & book1 ,
				 Book const & book2)
{
	int compare;
	compare = book1.author.compare(book2.author);
	if (compare == 0)
		return (book1.title < book2.title);
	return (compare < 0);
}

string getTitle(string const & raw)
{
	int begin = raw.find_first_of('"') + 1;
	int end = raw.find_last_of('"');
	return raw.substr(begin , end - begin);
}

string getAuthor(string const & raw)
{
	int begin = raw.find_last_of("by") + 2;
	return raw.substr(begin);
}

int getPosition(vector<Book> const & listBook ,
				string const & title)
{
	int size = listBook.size();
	for (int i = 0; i < size; ++i)
		if (title == listBook[i].title)
			return i;
}