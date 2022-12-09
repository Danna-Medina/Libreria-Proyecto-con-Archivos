#include "Sid.h"
#include "Book.h"
#include "User.h"

Sid::Sid() {
	LoadDB();
}

Sid::~Sid() {
	saveBD();
}

void  Sid::singUp(){
	User u;
	string name;
	string password;
	
	fflush(stdin);
	cout <<"Nombre: ";
	getline(cin, name);
	
	cout <<"Password: ";
	getline(cin, password);
	
	u.setId(usuarios.size() + 1);
	u.setName(name);
	u.setPassword(password);
	
	usuarios.push_back(u);

	cout << endl <<"                  Usuario agregado con exito " <<endl << endl;
	cout << "            Tu identificador personal es: " << u.getId() << endl << endl;
	
	file.open("user.txt", ios::app);
	file << u;
	file.close();
	
}


void Sid::logIn(){
	string pattern;
	size_t i;
	int id;
	
	cout <<"Identificador: ";
	cin >> id;
	cin.ignore();
	cout <<"Password: ";
	getline(cin, pattern);
	
	for(i = 0; i < usuarios.size(); i++){
		if(usuarios.at(i).getId() == id){
			if(usuarios.at(i).getPassword() == pattern){
				cout << endl << endl << "  \t  " << usuarios.at(i).getName() <<" Bienvenido a la plataforrma " << endl << endl;
				userId = id;
				userMenu();
			}
			else{
				cout << endl << endl << "                  Error en la contraseña  " << endl;
			}
			break;
		}
	}
	if(i == usuarios.size()){
		cout << "                  El usuario no se encontro... " << endl << endl;
	}
}


void Sid :: menu(){
	
	int opc;
	do {
		cout << endl<<endl<<"------------- PLATAFORMA BOOK'S D' -------------" << endl 
			<< "\t\t" << SINGUP << ".- Sign up "<< endl<<"\t\t" << 
			LOGIN << ".- Log in " << endl <<"\t\t" <<  
			EXIT << ".- Salir " << endl << "\t\t" << "--> ";
		
		cin >> opc ;
		
		cout << endl << endl;
		
		switch(opc){
		case SINGUP:
			cout << "********** REGISTRA TUS DATOS **********" << endl << endl;
			singUp();
			break;
		case LOGIN:
			cout << "********** INGRESA A TU CUENTA **********" << endl << endl;
			if (usuarios.size() > 0)
			{
				logIn();
			}
			else
			{
				cout << endl <<"                  No hay usuarios registrados." <<endl <<endl;
			}
			break;
		case EXIT:
			cout << "                  Adios!! " << endl;
			break;
		default:
			cout << "                  La opcion no existe... " << endl;
		}
	} while (opc != EXIT);
}


void Sid :: LoadDB(){
	Book b;
	User u;
	Book_User B;
	
	file.open("user.txt", ios::in);
	
	if(!file.is_open()){
		cout << "                  No es posible abrir el archivo de usuarios "<< endl;
	}
	else{
		while(file >> u){
			usuarios.push_back(u);
		}
	}
	file.close();
	
	file.open("books.txt", ios::in);
	if(!file.is_open()){
		cout << "                  No es posible abrir el archivo de libros "<< endl;
	}
	else{
		while(file >> b){
			books.push_back(b);
		}
	}
	file.close();
	
	file.open("prestados.txt", ios::in);
	if(!file.is_open()){
		cout << "                  No es posible abrir el archivo de prestados "<< endl;
	}
	else{
		while(file >> B){
			prestados.push_back(B);
		}
	}
	file.close();
}

void Sid :: userMenu(){
	int op;
	
	do {
		cout << endl << endl;
		cout << "\t\t" <<" Menu de usuario" << endl << endl
			<<"\t\t" <<SHOWLISTA << " Ver toda la lista" << endl 
			<< "\t\t" <<SHOWBOOK << " Buscar el libro" << endl
			<< "\t\t" <<PRESTADA << " Pedir prestamo" << endl
			<< "\t\t" <<SHOWPRESTADA << " Ver prestados" << endl
			<< "\t\t" <<EXITA << " Salir" << endl       
			<< "\t\t" <<"--> ";
		cin >> op;
		cin.ignore();
		
		cout << endl << endl;
		switch(op){
		case SHOWLISTA:
			cout << "                  Lista completa de libros" << endl<< endl;
			verlist();
			break;
			
		case SHOWBOOK:
			if(books.empty()){
				cout << "No hay libros aun" << endl;
			}
			else{
				bookMenu();
			}
			break;
			
		case PRESTADA:
			solicitarPrestada();
			break;
			
		case SHOWPRESTADA:
			showPrestado();
			break;
			
		case EXITA:
			cout << "                  Regresando a menu principal " << endl;
			break;
		default:
			cout << "                  No existe la opcion " << endl;
		}
		
	} while (op != EXITA);
}

void Sid :: verlist() const{
	list<Book>::const_iterator it;
	cout << "********** ID | TITULO | AUTOR | EDICION | INVENTARIO | DISPONIBLE **********" << endl << endl;
	
	if(books.empty()){
		cout << "                  No hay libros aun" << endl;
	}
	else{
		for(it=books.begin(); it != books.end(); ++it){
			cout << *it << endl;
		}
	}
}

void Sid :: bookMenu(){
	int opcion;
	
	do {
		cout << "\t\t" <<"  Menu de busqueda" << endl << endl
			<<"\t\t" <<BUSCARID << ".- Buscar por identificador" << endl 
			<< "\t\t" <<BUSCARTITLE << ".- Buscar por titulo" << endl
			<< "\t\t" <<BUSCARAUTOR << ".- Buscar por autor" << endl
			<< "\t\t" <<EXITA << ".- Salir" << endl << "\t\t" <<"--> ";
		
		cin >> opcion;
		
		cout << endl << endl;
		switch(opcion){
		case BUSCARID:
			cout << "                  Buscando por identificador" << endl;
			bucarId();
			break;
		case BUSCARTITLE:
			cout << "                  Buscando por titilo" << endl;
			buscarTitle();
			break;
		case BUSCARAUTOR:
			cout << "                  Buscando por autor" << endl;
			buscarAutor();
			break;
		case EXITB:
			cout << "                  Regresando a menu de usuarios" << endl;
			break;
		default:
			cout << "                  No existe la opcion " << endl;
		}
		
	} while (opcion != EXITA);
}

void Sid :: bucarId()const{
	list<Book>::const_iterator it;
	int id;
	cout << "Identificador: ";
	cin >> id;
	cout << endl << endl;
	cout << "********** ID | TITULO | AUTOR | EDICION | INVENTARIO | DISPONIBLE **********" << endl << endl;
	it = find_if(books.begin(), books.end(), [&id](const Book& b) -> bool
	{ return b.getid() == id;});
	if (it != books.end()){
		cout << *it << endl;
	} 
	else {
		cout << "                  El libro con ese id no existe" << endl;
	}
}
void Sid :: buscarTitle()const{
	string titulo;
	int cont = 0;
	
	list<Book>::const_iterator it= books.begin();
	fflush(stdin);
	cout << "Titulo: ";
	getline (cin,titulo);
	cout << endl;
	cout << "********** ID | TITULO | AUTOR | EDICION | INVENTARIO | DISPONIBLE **********" << endl << endl;
	while(it != books.end()) {
		
		it = find_if(it , books.end(), [&titulo](const Book &b) -> bool {
			return b.getTitle().find(titulo, 0) < b.getTitle().length();
		});
		
		if (it != books.end()){

			cout << endl <<(*it).getid() <<" | " <<(*it).getTitle() <<" | "
				<<(*it).getAuthor() <<" | " <<(*it).getEditionNumber() 
				<<" | " <<(*it).getInventory() <<" | " <<(*it).getAvailable() <<endl;
			++it;
			++cont;
		}
	}
	if (cont == 0){
		cout << "                  No existe el titulo del libro" << endl << endl;
	}
	cout << endl;
}
void Sid :: buscarAutor()const{
	string nombre;
	int cont = 0;
	cout << endl;
	list<Book>::const_iterator it = books.begin();
	fflush(stdin);
	cout << "Autor: ";
	getline (cin,nombre);
	cout << endl;
	cout << "********** ID | TITULO | AUTOR | EDICION | INVENTARIO | DISPONIBLE **********" << endl << endl;
	while(it != books.end()) {
		it = find_if(it , books.end(), [&nombre](const Book& b) -> bool {
			return b.getAuthor().find(nombre, 0) < b.getAuthor().size();}
		);
		if (it != books.end()){
			cout << endl <<(*it).getid() <<" | " <<(*it).getTitle() <<" | "
				<<(*it).getAuthor() <<" | " <<(*it).getEditionNumber() 
				<<" | " <<(*it).getInventory() <<" | " <<(*it).getEditionNumber() <<endl;
			++it;
			++cont;
		}
	}
	if (cont == 0){
		cout << "                  El autor no tiene libros aqui" << endl << endl;
	}
	cout << endl;
}

void Sid :: saveBD(){
	list<Book>::const_iterator it;
	file.open("books.txt", ios::out);
	if(!file.is_open()){
		cout << "  No esta ese libro " << endl << endl;
	}
	else{
		for(it=books.begin(); it!=books.end(); ++it){
			file << *it;
		}
	}
	file.close();
}

void Sid :: solicitarPrestada(){
	list<Book_User>::iterator it;
	list<Book>::iterator Bookit;
	size_t bookId;
	
	cout << "                  Pestamo de libros" << endl << endl;
	
	buscarTitle();
	
	do{
		cout << "Elige un libro (0 para cancelar) --> ";
		cin >> bookId;
	}while(bookId > books.size());
	
	--bookId;
	
	Bookit=books.begin();
	advance(Bookit, bookId);
	
	if(bookId < books.size()){
		if((*Bookit).getAvailable()){
		Book_User y;
		time_t dayone = time(0) + TiempoAll;
		
		tm* ltm = localtime(&dayone);
		
		y.setuserId(userId);
		y.setbookId((*Bookit).getid());
		y.setday(ltm->tm_mday);
		y.setmonth(ltm->tm_mon +1);
		y.setyear(ltm->tm_year + 1900);
		(*Bookit).setAvailable((*Bookit).getAvailable()-1);
		
		prestados.push_back(y);
		
		file.open("prestados.txt", ios::app);
		file << y;
		file.close();

		cout<<endl<< endl<<"                 Disfruta tu libro" << endl << endl;
		}
		else{
			cout << "                  Ya no hay libros disponibles" << endl << endl;
		}
	}
}

void Sid :: showPrestado(){
	list<Book_User>::iterator its;
	list<Book>::iterator bookIter;
	int uid = userId;
	int cont=0;
	
	its =prestados.begin();
	
	while(its != prestados.end()){
		its =find_if(its, prestados.end(), [&uid](const Book_User& x) -> bool {
			return x.getuserId() == uid;}
		);
		if(its != prestados.end()){
			bookIter= books.begin();
			advance(bookIter, (*its).getbookId()-1);
			cout << (*bookIter).getTitle() <<" se entrega el dia: " <<(*its).getday() <<"/" 
				<<(*its).getmonth()<<"/" <<(*its).getyear() << endl;
			++its;
			++cont;
		}	
	}
	if (cont == 0){
		cout << "                  No hay libros prestados" << endl << endl;
	}
	cout << endl;
}

