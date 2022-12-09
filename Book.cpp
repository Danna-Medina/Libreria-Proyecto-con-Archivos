#include "Book.h"

Book::Book() {
	Id = 0;
	title = "-"; 
	author = "-";
	editionNumber = 0;
	inventory = 0;
	available = 0;
}


int Book :: getid()const{
	return Id;
}
string Book :: getTitle()const{
	return title;
}
string Book :: getAuthor()const{
	return author;
}
int Book :: getEditionNumber()const{
	return editionNumber;
}
int Book :: getInventory()const{
	return inventory;
}
int Book :: getAvailable()const{
	return available;
}



void Book :: setid(const int y){
	Id = y;
}
void Book :: setTitle(const string &y){
	title = y;
}

void Book :: setAuthor(const string &y){
	author = y;
}

void Book :: setEditionNumber(const int y){
	editionNumber = y;
}

void Book :: setInventory(const int y){
	inventory = y;
}

void Book :: setAvailable(const int y){
	available = y;
}


ostream& operator << (ostream &out, const Book &v){
	out << v.getid() << "|"
		<< v.getTitle() << "|"
		<< v.getAuthor() << "|"
		<< v.getEditionNumber() << "|" 
		<< v.getInventory() << "|" 
		<< v.getAvailable() << endl;
	
	return out;
}

istream& operator >> (istream &is, Book &v){
	string a;
	getline(is, a, '|');
	
	if(a.size() > 0){
		v.setid(stoi(a));
		getline(is, a, '|');
		
		v.setTitle(a);
		getline(is, a, '|');
		
		v.setAuthor(a);
		getline(is, a, '|');
		
		v.setEditionNumber(stoi(a));
		getline(is, a, '|');
		
		v.setInventory(stoi(a));
		getline(is, a);
		
		v.setAvailable(stoi(a));
	}
	return is;
}
