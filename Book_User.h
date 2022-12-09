#ifndef BOOK_USER_H
#define BOOK_USER_H
#include "Book.h"

class Book_User {
public:
	Book_User();
	
	int getbookId()const;
	int getuserId()const;
	int getday()const;
	int getmonth()const;
	int getyear()const;
	
	void setbookId(const int y);
	void setuserId(const int y);
	void setday(const int y);
	void setmonth(const int y);
	void setyear(const int y);
	
	friend ostream& operator << (ostream &out, const Book_User &y);
	friend istream& operator >> (istream &is, Book_User &y);

private:
	int userId;
	int bookId;
	int day;
	int month;
	int year;
};

#endif

