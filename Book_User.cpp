#include "Book_User.h"

Book_User::Book_User() {

}

int Book_User :: getbookId()const{
	return bookId;
}
int Book_User :: getuserId()const{
	return userId;
}

int Book_User :: getday()const{
	return day;
}

int Book_User :: getmonth()const{
	return month;
}

int Book_User :: getyear()const{
	return year;
}


void Book_User :: setbookId(const int y){
	bookId = y;
}
void Book_User :: setuserId(const int y){
	userId = y;
}
void Book_User :: setday(const int y){
	day = y;
}
void Book_User :: setmonth(const int y){
	month = y;
}
void Book_User :: setyear(const int y){
	year = y;
}


ostream& operator << (ostream &out, const Book_User &y){
	out << y.getuserId() << "|"
		<< y.getbookId() << "|"
		<< y.getday() << "|"
		<< y.getmonth() << "|" 
		<< y.getyear() << endl;
	
	return out;
}

istream& operator >> (istream &is, Book_User &y){
	string a;
	getline(is, a, '|');
	
	if(a.size() > 0){
		y.setuserId(stoi(a));
		getline(is, a, '|');
		
		y.setbookId(stoi(a));
		getline(is, a, '|');
		
		y.setday(stoi(a));
		getline(is, a, '|');
		
		y.setmonth(stoi(a));
		getline(is, a);
		
		y.setyear(stoi(a));
	}
	return is;
}
