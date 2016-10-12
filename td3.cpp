// Separer les éléments

#include <iostream>
#include <vector>

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
		void setNumber (unsigned int n) {
			nb = n;
		}

		void setStreet (string s) {
			street = s;
		}
		
		void setZipCode (unsigned int z) {
			zipCode = z;

		}
		
		void setCity (string c) {
			city = c;
		}
		
		void setCountry (string c) {
			country = c;
		}

		void setAll(unsigned int n, string s, unsigned int z, string ci, string co){
			setNumber(n);
			setStreet(s);
			setZipCode(z);
			setCity(ci);
			setCountry(co);
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

		void addAdress(){ 
			string _street;
			string _city;
			string _country;
			unsigned int _nb, _zipCode;

			cout << "Rentrez le numero : " << endl;
			cin >> _nb;
			setNumber(_nb);

			cout << "Rentrez la rue : " << endl;
			cin >> _street;
			setStreet(_street);

			cout << "Rentrez le code postal : " << endl;
			cin >> _zipCode;
			setZipCode(_zipCode);

			cout << "Rentrez la ville : " << endl;
			cin >> _city;
			setCity(_city);

			cout << "Rentrez le pays : " << endl;
			cin >> _country;
			setCountry(_country);
		}


};

class Person
{
private:
	string name;
	unsigned int age;
	unsigned int height;
	Adress adress;

public:
	Person(){}
	void printAge() {
		cout << getAge() << " ans " << endl;
	}
	void printHeight() {
		cout << getHeight() << " cm " << endl;
	}
	void printName() {
		cout << getName() << endl;
	}
	void printAdress() {
		cout << adress.getNumber() << " " << adress.getStreet() << endl 
		<< adress.getZipCode() << " " << adress.getCity() << endl 
		<< adress.getCountry() << endl;
	}
	void printAll(){
		printName();
		printAge();
		printHeight();
		printAdress();
		cout << endl;
	}

	string getName() {
		return name;
	}

	unsigned int getAge() {
		return age;
	}

	unsigned int getHeight() {
		return height;
	}

	void setName (string n) {
		name = n;
	}
	void setAge (unsigned int a) {
		age = a;
	}
	int setHeight (unsigned int h) {
		if (h > 0 && h < 1000) {
			height = h;
			return 1;
		}
		return 0;
	}
	void setAdress(Adress a){
		adress = a;
	}
	void setAll(string n, unsigned int a, unsigned int h, Adress ad){
		setName(n);
		setAge(a);
		setHeight(h);
		setAdress(ad);
	}

	void addInfos(){
		string _name;
		unsigned int _age, _height;
		Adress _adress;

		cout << "Rentrez le nom : " << endl;
		cin >> _name;
		setName(_name);

		cout << "Rentrez l'age : " << endl;
		cin >> _age;
		setAge(_age);

		cout << "Rentrez la taille : " << endl;
		cin >> _height;
		setHeight(_height);

		cout << "Vous allez rentrer l'adresse" << endl;	
		adress.addAdress();
	}
};

class AdressBook{
	private:
		vector<Person> adressBook;

	public:
		AdressBook(){}

		void addContact(Person p){
			adressBook.push_back(p);
			cout << "Vous venez de rentrer le contact "  << endl;
			p.printAll();	
			cout << endl;
		}

		void addContact(){
			Person p;
			cout << "----------------------- NOUVEAU CONTACT ----------------------"  << endl << endl;
			p.addInfos();

			adressBook.push_back(p);

			cout << "Vous venez de rentrer le contact "  << endl;
			p.printAll();	
			cout << "---------------------------------------------"  << endl << endl;
		}

		Person searchContact(string _name){
			cout << "----------------------- RECHERCHE ----------------------"  << endl << endl;
			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					cout << "Ce contact existe :"  << endl;
 					adressBook[i].printAll();
 					cout << "---------------------------------------------"  << endl << endl;
 					return adressBook[i];	
 				}
 			}
 			Person p;
 			cout << "Ce contact n'existe pas"  << endl;
 			cout << "---------------------------------------------"  << endl << endl;
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

		void editContact(Person p){ // a faire

		}

		void removeContact(Person p){
			cout << "----------------------- SUPPRESSION D'UN CONTACT ----------------------"  << endl << endl;
			int position = searchContactPlace(p);
			if(position == -1){
				cout << "Ce contact n'existe pas, et ne peut donc pas être supprimé" << endl << endl;
			}else{
				cout << "Vous allez supprimer ce contact" << endl;
				p.printAll();
				adressBook.erase(adressBook.begin()+position);
				cout << "Ce contact a été supprimé" << endl << endl;
				cout << "-------------------------------------------------" << endl << endl;
			}
			
		}

		void exportToFile(){ //a faire

		}

		void print(){
			vector<int>::size_type sz = adressBook.size();
			int nbTest = 0, limite = 10;
			string junk;
			cout << "----------------------- LISTE DES CONTACTS : 10max affiché ----------------------"  << endl << endl;
 			for (unsigned i=0; i<sz; i++) {
 				if(nbTest < limite){
 					nbTest ++;
 					cout << "Contact : "  << i << endl;
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


void testContacts(AdressBook *book){
	Person a,b,c,d,e,f,g,h,i,j,k,l,m,n;
	Adress _a,_b,_c,_d,_e,_f,_g,_h,_i,_j,_k,_l,_m,_n;
	_a.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	a.setAll("JeanMiche1", 23, 180, _a);
	_b.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	b.setAll("JeanMiche2", 23, 180, _b);
	_c.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	c.setAll("JeanMiche3", 23, 180, _c);
	_d.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	d.setAll("JeanMiche4", 23, 180, _d);
	_e.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	e.setAll("JeanMiche5", 23, 180, _e);
	_f.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	f.setAll("JeanMiche6", 23, 180, _f);
	_g.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	g.setAll("JeanMiche7", 23, 180, _g);
	_h.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	h.setAll("JeanMiche8", 23, 180, _h);
	_i.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	i.setAll("JeanMiche9", 23, 180, _i);
	_j.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	j.setAll("JeanMiche10", 23, 180, _j);
	_k.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	k.setAll("JeanMiche11", 23, 180, _k);
	_l.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	l.setAll("JeanMiche12", 23, 180, _l);
	_m.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	m.setAll("JeanMiche13", 23, 180, _m);
	_n.setAll(20, "Rue des fleurs", 77420, "Paris", "Canada");
	n.setAll("JeanMiche14", 23, 180, _n);

	book->addContact(a);
	book->addContact(b);
	book->addContact(c);
	book->addContact(d);
	book->addContact(e);
	book->addContact(f);
	book->addContact(g);
	book->addContact(h);
	book->addContact(i);
	book->addContact(j);
	book->addContact(k);
	book->addContact(l);
	book->addContact(m);
	book->addContact(n);

}

void menu(){ // a faire en pratique
	cout << "----------------------MENU PRINCIPAL--------------------------" << endl;
	cout << "1) Affichez les contacts \t 2) Cherchez un contact \t 3) Ajoutez un contact" <<
	"\t 4) Supprimez un contact \t 5) Editez un contact \t Exportez" << endl;
}




int main () {
	AdressBook book;
	Person test;
	Adress _test;

	_test.setAll(20, "Rue des pigeons", 77420, "Paris", "France");
	test.setAll("Eustache", 23, 180, _test);
	book.addContact(test);

	testContacts(&book);



	book.print();

	book.searchContact("JeanMiche14");

	book.removeContact(test);

	book.print();

	return 0;
}