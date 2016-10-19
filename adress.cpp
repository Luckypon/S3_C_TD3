#include "adress.h"




Adress::Adress(){};
void Adress::setNumber (unsigned int n) {nb = n;}
void Adress::setNumber () {
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

void Adress::setStreet (string s) {street = s;}
void Adress::setStreet () {
	bool test;
	string _street = "";
	do{
		cout << "Street : " << endl;
		getline (cin,_street);
		if(cin.fail() || _street == ""){
			cout << "The street was incorrect ! " << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}else{
			street = _street;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			test = 0;
		}
	}while(test);

}

void Adress::setZipCode (unsigned int z) {zipCode = z;}
void Adress::setZipCode () {
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

void Adress::setCity (string c) {city = c;}
void Adress::setCity () {
	bool test;
	string _city = "";
	do{
		cout << "City : " << endl;
		getline (cin,_city);
		if(cin.fail() || _city == ""){
			cout << "The city was incorrect ! " << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}else{
			city = _city;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			test = 0;
		}
	}while(test);
}

void Adress::setCountry (string c) {country = c;}
void Adress::setCountry () {
	bool test;
	string _country = "";
	do{
		cout << "Country : " << endl;
		getline (cin,_country);
		if(cin.fail() || _country == ""){
			cout << "The country was incorrect ! " << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}else{
			country = _country;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			test = 0;
		}
	}while(test);
}

void Adress::setAdress(unsigned int n, string s, unsigned int z, string ci, string co){
	setNumber(n);
	setStreet(s);
	setZipCode(z);
	setCity(ci);
	setCountry(co);
}
void Adress::setAdress(){ 	
	cout << "You're going to enter the adress" << endl;
	setNumber();
	setStreet();
	setZipCode();
	setCity();
	setCountry();
}


unsigned int Adress::getNumber () {
	return nb;
}

string Adress::getStreet () {
	return street;
}

unsigned int Adress::getZipCode () {
	return zipCode;
}

string Adress::getCity () {
	return city;
}

string Adress::getCountry () {
	return country;
}

