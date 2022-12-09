#ifndef USER_H
#define USER_H

#include<iostream>
using namespace std;


class User {
public:
	User();
	
	int getId()const;
	string getName() const;
	string getPassword() const;
	
	void setId(const int x);
	void setName(const string &x);
	void setPassword(const string &x);
	
	friend ostream& operator << (ostream &os, const User &u);
	friend istream& operator >> (istream &in, User &u);
	
private:
	int id;
	string name;
	string password;
};

#endif

