#ifndef BOOK_H
#define BOOK_H

#include<iostream>
using namespace std;


class Book {
public:
	Book();
	
	int getid()const;
	string getTitle()const;
	string getAuthor()const;
	int getEditionNumber()const;
	int getInventory()const;
	int getAvailable()const;
	
	void setid(const int y);
	void setTitle(const string &y);
	void setAuthor(const string &y);
	void setEditionNumber(const int y);
	void setInventory(const int y);
	void setAvailable(const int y);
	
	friend ostream& operator << (ostream &out, const Book &v);
	friend istream& operator >> (istream &is, Book &v);
	
private:
	int Id;
	string title;
	string author;
	int editionNumber;
	int inventory;
	int available;
};

#endif

