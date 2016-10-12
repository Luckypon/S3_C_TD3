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

		void addContact(){
			Person p;
			
			p.addInfos();

			adressBook.push_back(p);

			cout << "Vous venez de rentrer le contact "  << endl;	
		}
		void removeContact(){

		}
		void print(){
			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
				adressBook[i].printAll();
				cout << endl;
			}
		}

};







int main () {
	AdressBook book;
	book.addContact();
	book.print();

	return 0;
}