#ifndef ADRESS_H
#define ADRESS_H

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

		Adress();
		void setNumber (unsigned int n);
		void setNumber ();

		void setStreet (string s);
		void setStreet ();

		void setZipCode (unsigned int z);
		void setZipCode ();

		void setCity (string c);
		void setCity ();
		void setCountry (string c);
		void setCountry ();

		void setAdress(unsigned int n, string s, unsigned int z, string ci, string co);
		void setAdress();

		unsigned int getNumber ();
		string getStreet ();

		unsigned int getZipCode ();

		string getCity ();
		string getCountry ();

};

#endif