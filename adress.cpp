#include "adress.h"
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
		// Adress(){};
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