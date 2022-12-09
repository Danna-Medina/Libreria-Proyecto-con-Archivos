#ifndef SID_H
#define SID_H

#include "Book.h"
#include "User.h"
#include "Book_User.h"
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <ctime>

class Sid {
public:
	Sid();
	~Sid();
	
	void menu();
	void singUp();
	void logIn();
	
	void LoadDB();
	void userMenu();
	
	void bookMenu();
	void verlist() const;

	void bucarId() const;
	void buscarTitle() const;
	void buscarAutor() const;
	
	void saveBD();
	void solicitarPrestada();
	void showPrestado();
	void verlista() const;
	
private:
	vector<User>usuarios;
	list<Book> books;
	list<Book_User> prestados;
	
	int userId;
	const int SegundosDay = 60*60*24;
	const int TiempoAll = SegundosDay*7;
	
	fstream file;
	enum opcion
	{
		EXIT,
		SINGUP,
		LOGIN,
	};
	enum opciones
	{
		EXITA,
		SHOWLISTA,
		SHOWBOOK,
		PRESTADA,
		SHOWPRESTADA
	};
	enum opc
	{
		EXITB,
		BUSCARID,
		BUSCARTITLE,
		BUSCARAUTOR,
	};

};

#endif

