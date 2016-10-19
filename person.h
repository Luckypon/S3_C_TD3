#ifndef PERSON_H
#define PERSON_H

#include "adress.h"

#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <string>

using namespace std;


class Person
{
private:
	string name;
	unsigned char phoneNb[10];

	Adress adress;

public:
	Person();
	void printPhoneNb();
	void printName();
	void printAdress();


	void printAll();
	string getName() ;
	unsigned char* getPhoneNb() ;

	Adress getAdress();
	void setName (string n);
	void setName ();

	void setPhoneNb (unsigned char nb[]);
	void setPhoneNb ();
	void setAdress(Adress a);
	void setAll(string n, unsigned char nb[], Adress ad);

	void addInfos();
};



#endif