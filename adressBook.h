#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include "adress.h"
#include "person.h"


#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

class AdressBook{
	private:
		vector<Person> adressBook;

	public:
		AdressBook();

		void addContact(Person p);
		void addContact();

		int searchNamesake(string _name);

		Person searchContact(string _name);


		Person searchContact();

		int searchContactPlace(Person p);

		int searchContactPlace(string _name);
		void editContact();
		void removeContact();

		void exportToFile();

		void getContactFromFile();
		void print();

};



#endif