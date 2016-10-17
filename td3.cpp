// Separer les éléments
// vérifier la sécurité
// problème avec les espaces ?


/* 

	verifier si le contact existe deja
	en regle général, quand on ecrit une btise ca bug, il faut faire des tests
	dans edit, quand on met une valeur qui n'est pas acceptée par le menu ca revient au menu principal

*/

	

#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

class Adress
	{
	private:
		unsigned int nb;
		string street;
		unsigned int zipCode;
		string city;
		string country;

	public:
		Adress(){};
		void setNumber (unsigned int n) {nb = n;}
		void setNumber () {
			unsigned int _nb = 0;
			do{
				cout << "Number : " << endl;
				cin >> _nb;
				if(cin.fail() || _nb == 0){
					cout << "The number was incorrect ! " << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}else{
					nb = _nb;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}while(_nb == 0);
		}

		void setStreet (string s) {street = s;}
		void setStreet () {
			string _street = "";
			do{
				cout << "Street : " << endl;
				cin >> _street;
				if(cin.fail() || _street == ""){
					cout << "The street was incorrect ! " << _street << endl;
					_street == "";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}else{
					street = _street;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}while(_street == "");
		}
		
		void setZipCode (unsigned int z) {zipCode = z;}
		void setZipCode () {
			unsigned int _code;
			do{
				cout << "ZipCode (5 caracteres) : " << endl;
				cin >> _code;
				if(cin.fail() || _code < 10000 || _code > 99999){
					cout << "The zipCode was incorrect ! " << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}else{
					zipCode = _code;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}while(_code < 10000 || _code > 99999);
		}
		
		void setCity (string c) {city = c;}
		void setCity () {
			string _city = "";
			do{
				cout << "City : " << endl;
				cin >> _city;
				if(cin.fail() || _city == ""){
					cout << "The city was incorrect ! " << _city << endl;
					_city == "";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}else{
					city = _city;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}while(_city == "");
		}
		
		void setCountry (string c) {country = c;}
		void setCountry () {
			string _country = "";
			do{
				cout << "Country : " << endl;
				cin >> _country;
				if(cin.fail() || _country == ""){
					cout << "The country was incorrect ! " << _country << endl;
					_country == "";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}else{
					country = _country;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}while(_country == "");
		}

		void setAdress(unsigned int n, string s, unsigned int z, string ci, string co){
			setNumber(n);
			setStreet(s);
			setZipCode(z);
			setCity(ci);
			setCountry(co);
		}
		void setAdress(){ 	
			cout << "Vous allez rentrer l'adresse" << endl;
			setNumber();
			setStreet();
			setZipCode();
			setCity();
			setCountry();
		}


		unsigned int getNumber () {
			return nb;
		}

		string getStreet () {
			return street;
		}

		unsigned int getZipCode () {
			return zipCode;
		}

		string getCity () {
			return city;
		}

		string getCountry () {
			return country;
		}

		
};



class Person
{
private:
	string name;
	unsigned char phoneNb[10];

	Adress adress;

public:
	Person(){}
	void printPhoneNb() {
		unsigned char* val = getPhoneNb();
		
		for (int i = 0; i < 10; i++) {
			cout << val[i];
			if (i%2 == 1) cout << " ";
		}
		cout << endl;
	}
	
	void printName() {
		cout << getName() << endl;
	}

	void printAdress() {
		cout << adress.getNumber() << " " << adress.getStreet() << endl 
		<< adress.getZipCode() << " " << adress.getCity() << endl 
		<< adress.getCountry() << endl;
	}

	Adress getAdress() {
		return adress;
	}




	void printAll(){
		printName();
		printPhoneNb();
		printAdress();
		cout << endl;
	}

	string getName() {
		return name;
	}
	unsigned char* getPhoneNb() {
		return phoneNb;
	}

	void setName (string n) {name = n;}
	void setName () {
		string _name = "";
		do{
			cout << "Name : " << endl;
			cin >> _name;
			if(cin.fail() || _name == ""){
				cout << "The name was incorrect ! " << _name << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}else{
				name = _name;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}while(_name == "");
	}

	void setPhoneNb (unsigned char nb[]) {
		for (int i = 0; i < 10; i++) {
				phoneNb[i] = nb[i];
		}
	}
	void setPhoneNb () {
		cout << "Phone number : " << endl;
		unsigned char val;
		int i = 0;
		while (i < 10) {
			cin >> val;
			if (val <= 57 && val >= 48) {
				phoneNb[i] = val;
				i++;
			}
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void setAdress(Adress a){
		adress = a;
	}
	void setAll(string n, unsigned char nb[], Adress ad){
		setName(n);
		setPhoneNb(nb);
		setAdress(ad);
	}

	void addInfos(){
		setName();
		setPhoneNb();
		adress.setAdress();
	}
};


class AdressBook{
	private:
		vector<Person> adressBook;

	public:
		AdressBook(){}

		void addContact(Person p){
			adressBook.push_back(p);
			// cout << endl;
			// cout << "Vous venez de rentrer le contact :"  << endl;
			// p.printAll();	
			// cout << endl;
		}

		void addContact(){
			Person p;
			cout << "----------------------- NEW CONTACT ----------------------"  << endl << endl;
			p.addInfos();

			adressBook.push_back(p);
 			
 			cout << endl;
			cout << "Vous venez de rentrer le contact :"  << endl;
			p.printAll();	
			cout << "---------------------------------------------"  << endl << endl;
		}


		Person searchContact(string _name){
			cout << "----------------------- SEARCH ----------------------"  << endl << endl;

			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					cout << "This contact exist :"  << endl;
 					adressBook[i].printAll();
 					// cout << "---------------------------------------------"  << endl;
 					cout << endl;
 					return adressBook[i];	
 				}
 			}
 			Person p;
 			cout << "This contact doesn't exist"  << endl;
 			// cout << "---------------------------------------------"  << endl << endl;
			return p;
		}


		Person searchContact(){
			cout << "----------------------- SEARCH ----------------------"  << endl << endl;
			string _name;
			cout << "Contact to find :"  << endl;
			cin >> _name;
 			cout << endl;

			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					cout << "This contact exist :"  << endl;
 					adressBook[i].printAll();
 					// cout << "---------------------------------------------"  << endl << endl;
 					cout << endl;
 					return adressBook[i];	
 				}
 			}
 			Person p;
 			cout << "This contact doesn't exist"  << endl;
 			// cout << "---------------------------------------------"  << endl << endl;
			return p;
		}


		int searchContactPlace(Person p){
			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(p.getName() == adressBook[i].getName()){ //a modifier ?? deux personnes peuvent avoir le même nom..
 					return i;	
 				}
 			}
 			return -1;
		}

		int searchContactPlace(string _name){
			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					return i;	
 				}
 			}
 			return -1;
		}

		void editContact(){ // a faire
			cout << "----------------------- EDIT A CONTACT ----------------------"  << endl << endl;
			
			string _name;
			cout << "Contact to edit :"  << endl;
			cin >> _name;
 			cout << endl;
 			int posContactToEdit = searchContactPlace(_name);
 			if (posContactToEdit < 0) {
 				cout << "This contact doesn't exist"  << endl;
 			} else {
	 			Person & p =  adressBook[posContactToEdit];
	 			
	 			vector<int>::size_type sz = adressBook.size();
	 			for (unsigned i=0; i<sz; i++) {
	 				if(_name == adressBook[i].getName()){

	 					cout << endl;

	 					cout << "Info to edit :"  << endl;
	 					cout << "\t1) Name"  << endl;
	 					cout << "\t2) Phone number"  << endl;
	 					cout << "\t3) Adress"  << endl;

	 					// cout << "---------------------------------------------"  << endl << endl;
	 					cout << endl;



				        int option = -1;
				        cin >> option;
				        while (option < 0) {

					        if (cin.fail() || (option != 1 && option != 2 && option != 3 ))
					        {
								cout << "\x1B[2J\x1B[H";
					            cout << "This is not an option..." << endl;
					            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer until the new line char.
					        } 

					    }

					    if (option == 1) {

							cout << "New name : " << endl;
							cin >> _name;
							p.setName(_name);

						}
						else if (option == 2) {
							cout << "New phone number : " << endl;
							unsigned char val;
							unsigned char _phoneNb[10];
							int i = 0;
							while (i < 10) {
								cin >> val;
								if (val <= 57 && val >= 48) {
									_phoneNb[i] = val;
									i++;
								}
							}
							
							p.setPhoneNb(_phoneNb);

	 					}
						else if (option == 3) {
							cout << "New adress : " << endl;
							Adress _adress;
							_adress.setAdress();
							p.setAdress(_adress);						
	 					}

	 					cout << endl << "The contact had bin edited" << endl;
	 					p.printAll();
	 				}
				}
			}
 			// cout << "This contact doesn't exist, "  << endl;

		}

		void removeContact(){
			cout << "----------------------- SUPPRESSION D'UN CONTACT ----------------------"  << endl << endl;
			
			string _name;
			cout << "Contact to remove :"  << endl;
			cin >> _name;
 			cout << endl;
 			Person p = searchContact(_name);

			int position = searchContactPlace(p);
			if(position == -1){
				// cout << "Ce contact n'existe pas, et ne peut donc pas être supprimé" << endl << endl;
			}else{
				cout << "You are going to remove the contact : " << endl;
				p.printAll();
				adressBook.erase(adressBook.begin()+position);
				cout << "This contact had bin removed" << endl << endl;
				// cout << "-------------------------------------------------" << endl << endl;
			}
			
		}

		void exportToFile(){ // à tester
			cout << "----------------------- EXPORT CONTACTS ----------------------"  << endl << endl;
			ofstream myfile;
			myfile.open("AdressBook.txt");
			if (myfile.is_open()){
				vector<int>::size_type sz = adressBook.size();

				myfile << "\t MY CONTACTS\n\n\n";

 				for (unsigned i=0; i<sz; i++) {
 					// myfile << "This is a line.\n";
					myfile << "CONTACT " << i+1 << ".\nName : ";

					myfile <<  adressBook[i].getName() << " \nPhone : " << adressBook[i].getPhoneNb();
					myfile << "\nAdress : ";
					// myfile <<  adressBook[i].printAdress();
					myfile <<  adressBook[i].getAdress().getNumber() << " " << adressBook[i].getAdress().getStreet() << "\n\t";
					myfile <<  adressBook[i].getAdress().getZipCode() << " " << adressBook[i].getAdress().getCity() << "\n\t";
					myfile <<  adressBook[i].getAdress().getCountry();
					// myfile << "\n Next Contact \n";
					myfile << "\n\n";

 				}
				myfile.close();
				cout << "The contacts had bin export in the file \"AdressBook.txt\". "  << endl << endl;

			}
			else{
				cout << "Unable to open file";
			} 
			// return 0;
		}


		void getContactFromFile(){ // à tester
			
			// faire une boucle pour recuperer les plusieurs contacts
			// on ne peut pas editer un contact qui a ete recuperer comme ça, on met une lettre de trop
    		string line;
			ifstream myfile ("AdressBook.txt");
			if (myfile.is_open()){
				int i = 0;
				
			    while ((getline (myfile,line)) && (line != "CONTACT 1.") )
			    { 
			    } // go to the first contact name line
			    
			    myfile.seekg (6, ios::cur); //go to name

			    char car;
			    const int TAILLE_TAB = 10;
			    char tabChar[TAILLE_TAB];
			    myfile.get(car);
			    const int LINE_RETURN = 10;
			    const int TWO_POINTS = 58;
			    const int SPACE = 32;
			    const int ZERO = 48;
			    
			    while ( myfile.get(car) && car != LINE_RETURN) {
			    	tabChar[i] = car;
			    	i++;
			    }
			    string _name (tabChar, i-3);
 				
 				// go to the phone number
 				i = 0;
 				while ( myfile.get(car) && car != TWO_POINTS) {
			    }
 				myfile.get(car);
 				unsigned char phoneNumber[10];

 				while ( myfile.get(car) && car != LINE_RETURN) {
			    	phoneNumber[i] = car;
			    	i++;
			    }

			    // go to adress (number)
 				while ( myfile.get(car) && car != TWO_POINTS) {
			    }
 				myfile.get(car);
 				unsigned int nb = 0;
 				while ( myfile.get(car) && car != SPACE) {
			    	nb = nb*10 + (car - ZERO);
			    }

			    // get street
			    for (i = 0; i < TAILLE_TAB; i++) 
			    	tabChar[i] = 0;

			    i = 0;
 				while ( myfile.get(car) && car != LINE_RETURN) {
					tabChar[i] = car;
			    	i++;
			    }
			    string _street(tabChar);


 				// go to zipCode 
				myfile.get(car);	//pass TAB
 				unsigned int zip = 0;
 				while ( myfile.get(car) && car != SPACE) {
			    	zip = zip*10 + (car - ZERO);
			    }


			    // get city
			    for (i = 0; i < TAILLE_TAB; i++) 
			    	tabChar[i] = 0;

			    i = 0;
 				while ( myfile.get(car) && car != LINE_RETURN) {
					tabChar[i] = car;
			    	i++;
			    }
			    string _city(tabChar);


			    // get country
			    for (i = 0; i < TAILLE_TAB; i++) 
			    	tabChar[i] = 0;

			    i = 0;
				myfile.get(car);	//pass TAB
 				while ( myfile.get(car) && car != LINE_RETURN) {
					tabChar[i] = car;
			    	i++;
			    }
			    string _country(tabChar);



				Person p;
				Adress a;
			 	a.setAdress(nb, _street, zip, _city, _country);
				p.setAll(_name, phoneNumber, a);
				addContact(p);

				myfile.close();
				  // cout << "size is: " << (begin) << (end-begin) << " bytes.\n";
			}
			
		}



		void print(){
			vector<int>::size_type sz = adressBook.size();
			int nbTest = 0, limite = 10;
			string junk;
			cout << "----------------------- LIST OF CONTACTS : 10max printed ----------------------"  << endl << endl;
 			for (unsigned i=0; i<sz; i++) {
 				if(nbTest < limite){
 					nbTest ++;
 					cout << "Contact : "  << i+1 << endl;
					adressBook[i].printAll();
					cout << endl;
 				}else{
 					cout << "Pressez un bouton pour voir les autres contacts "  << endl << endl;
 					cin >> junk;
 					nbTest = 0;
 					cout << endl;
 				}
 				
			}
			cout << "-------------------------------------------------" << endl << endl;
		}

};


// void testContacts(AdressBook *book){
// 	Person a,b,c,d,e,f,g,h,i,j,k,l,m,n;
// 	Adress _a,_b,_c,_d,_e,_f,_g,_h,_i,_j,_k,_l,_m,_n;
// 	_a.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	a.setAll("JeanMiche1", 180, _a);
// 	_b.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	b.setAll("JeanMiche2", 180, _b);
// 	_c.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	c.setAll("JeanMiche3", 180, _c);
// 	_d.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	d.setAll("JeanMiche4", 180, _d);
// 	_e.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	e.setAll("JeanMiche5", 180, _e);
// 	_f.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	f.setAll("JeanMiche6", 180, _f);
// 	_g.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	g.setAll("JeanMiche7", 180, _g);
// 	_h.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	h.setAll("JeanMiche8", 180, _h);
// 	_i.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	i.setAll("JeanMiche9", 180, _i);
// 	_j.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	j.setAll("JeanMiche10", 180, _j);
// 	_k.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	k.setAll("JeanMiche11", 180, _k);
// 	_l.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	l.setAll("JeanMiche12", 180, _l);
// 	_m.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	m.setAll("JeanMiche13", 180, _m);
// 	_n.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
// 	n.setAll("JeanMiche14", 180, _n);

// 	book->addContact(a);
// 	book->addContact(b);
// 	book->addContact(c);
// 	book->addContact(d);
// 	book->addContact(e);
// 	book->addContact(f);
// 	book->addContact(g);
// 	book->addContact(h);
// 	book->addContact(i);
// 	book->addContact(j);
// 	book->addContact(k);
// 	book->addContact(l);
// 	book->addContact(m);
// 	book->addContact(n);

// }

class Menu { // a faire en pratique

	private:
    AdressBook & book;
    /*Just print the main screen*/
    void main_screen()
    {
        // cout << "Welcome! Please, tell me what do you want..." << std::endl;
        // cout << "1) Add Person" << std::endl;
        // cout << "0) Exit" << std::endl;
    
        cout << endl;

    	cout << "----------------------MAIN MENU --------------------------" << endl;
        cout << endl;
	
		cout << "\t 1) Show contacts" 
	<< endl << "\t 2) Search a contact " 
	<< endl << "\t 3) Add a new contact"
	<< endl << "\t 4) Remove a contact" 
	<< endl << "\t 5) Edit a contact"
	<< endl << "\t 6) Export"
	<< endl << "\t 0) Quit" << endl << endl;




    }
//     /*Here we check if input is correct.*/
    int input()
    {
        int option = -1;
        cin >> option;
        if (cin.fail() || (option != 0 && option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6))
        {
			cout << "\x1B[2J\x1B[H";
            cout << "This is not an option..." << endl;
            cin.clear(); // clear errors
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer until the new line char.
            return -1;
        }
        else
            return option;

    }

public:
    Menu(AdressBook & addr) : book(addr) {}

    void start()
    {
        int option = -1;
        do
        {
            main_screen();
            option = input();

			
			/* afficher les contacts */
            if (option == 1) {
	  			book.print();
			} /* chercher un contact */
			else  if (option == 2) {
				book.searchContact();
			} /* ajoutez un contact */
			else  if (option == 3) { 
				book.addContact();
			} /* Supprimez un contact */
			else  if (option == 4) {
   				book.removeContact();
			}
			/* 5) Editez un contact */
			else  if (option == 5) {
  				book.editContact();
			}
 			/* 6) Exportez */
			else  if (option == 6) {
				book.exportToFile();
			}

        } while (option != 0);

    }


};





int main () {
	AdressBook book;
	book.getContactFromFile();
	// Person test;
	// Adress _test;
	Menu menu(book);
	menu.start();

	// _test.setAll(20, "Rue des pigeons", 77420, "Paris", "France");
	// test.setAll("Eustache", 23, 180, _test);
	// book.addContact(test);

	// testContacts(&book);



	// book.print();

	// book.searchContact("JeanMiche14");

	// book.removeContact(test);

	// book.print();

	return 0;
}