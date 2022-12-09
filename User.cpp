#include "User.h"

User::User() {
	id = 0;
	name = "-";
	password = "-";
}

int User :: getId()const{
	return id;
}

string User:: getName() const{
	return name;
}

string User :: getPassword() const{
	return password;
}



void User :: setId(const int x){
	id = x;
}

void User :: setName(const string &x){
	name = x;
}

void User :: setPassword(const string &x){
	password = x;
}


ostream& operator << (ostream &os, const User &u){
	os << u.getId() << "|" 
		<< u.getName() << "|" 
		<< u.getPassword() << endl;
	return os;
}

istream& operator >> (istream &in, User &u){
	string a;
	getline(in, a, '|');
	
	if(a.size() > 0){
		u.setId(stoi(a));
		getline(in, a, '|');
		
		u.setName(a);
		getline(in, a);
		
		u.setPassword(a);
	}
	return in;
}
