#include "person.h"


	Person::Person(){}
	void Person::printPhoneNb() {
		unsigned char* val = getPhoneNb();
		
		for (int i = 0; i < 10; i++) {
			cout << val[i];
			if (i%2 == 1) cout << " ";
		}
		cout << endl;
	}
	
	void Person::printName() {
		cout << getName() << endl;
	}

	void Person::printAdress() {
		cout << adress.getNumber() << " " << adress.getStreet() << endl 
		<< adress.getZipCode() << " " << adress.getCity() << endl 
		<< adress.getCountry() << endl;
	}

	void Person::printAll(){
		printName();
		printPhoneNb();
		printAdress();
		cout << endl;
	}

	string Person::getName() {
		return name;
	}
	unsigned char* Person::getPhoneNb() {
		return phoneNb;
	}

	Adress Person::getAdress() {
		return adress;
	}

	void Person::setName (string n) {name = n;}
	void Person::setName () {
		bool test;
		string _name = "";
		do{
			cout << "Name : " << endl;
			getline (cin,_name);
			if(cin.fail() || _name == ""){
				cout << "The name was incorrect ! " << endl;
			}else{
				name = _name;
				test = 0;
			}
		}while(test);

	}

	void Person::setPhoneNb (unsigned char nb[]) {
		for (int i = 0; i < 10; i++) {
				phoneNb[i] = nb[i];
		}
	}
	void Person::setPhoneNb () {
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

	void Person::setAdress(Adress a){
		adress = a;
	}
	void Person::setAll(string n, unsigned char nb[], Adress ad){
		setName(n);
		setPhoneNb(nb);
		setAdress(ad);
	}

	void Person::addInfos(){
		setName();
		setPhoneNb();
		adress.setAdress();
	}
