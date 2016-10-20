#include "adressBook.h"



		AdressBook::AdressBook(){}

		void AdressBook::addContact(Person p){
			adressBook.push_back(p);
		}

		void AdressBook::addContact(){
			Person p;
			cout << "----------------------- NEW CONTACT ----------------------"  << endl << endl;
			p.addInfos();

			if(searchNamesake(p.getName()) == 1){
				cout << endl << "Someone already have the same name, so '2' will be added at the end of his name:"  << endl;
				p.setName(p.getName() + " 2");
			}

			adressBook.push_back(p);
 			
 			cout << endl;
			cout << "You have entered a contact :"  << endl;
			p.printAll();	
			cout << "---------------------------------------------"  << endl << endl;
		}

		int AdressBook::searchNamesake(string _name){
			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					return 1;	
 				}
 			}
			return 0;
		}


		Person AdressBook::searchContact(string _name){
			cout << "----------------------- SEARCH ----------------------"  << endl << endl;

			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					cout << "This contact exist :"  << endl;
 					adressBook[i].printAll();
 					cout << endl;
 					return adressBook[i];	
 				}
 			}
 			Person p;
 			cout << "This contact doesn't exist"  << endl;
			return p;
		}


		Person AdressBook::searchContact(){
			cout << "----------------------- SEARCH ----------------------"  << endl << endl;

 			vector<int>::size_type sz = adressBook.size();
			string _name = "";

			cout << "Contact to find : " << endl;
			getline(cin,_name);
			cout << endl;
		
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					cout << "This contact exist :"  << endl;
 					adressBook[i].printAll();
 					cout << endl;
 					return adressBook[i];	
 				}
 			}

 			Person p;
 			cout << "This contact doesn't exist"  << endl;
			return p;
		}


		int AdressBook::searchContactPlace(Person p){
			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(p.getName() == adressBook[i].getName()){ 
 					return i;	
 				}
 			}
 			return -1;
		}

		int AdressBook::searchContactPlace(string _name){
			vector<int>::size_type sz = adressBook.size();
 			for (unsigned i=0; i<sz; i++) {
 				if(_name == adressBook[i].getName()){
 					return i;	
 				}
 			}
 			return -1;
		}

		void AdressBook::editContact(){
			cout << "----------------------- EDIT A CONTACT ----------------------"  << endl << endl;
			
			string _name;
			cout << "Contact to edit :"  << endl;
			getline (cin,_name);
 			cout << endl;
 			int posContactToEdit = searchContactPlace(_name);
 			if (posContactToEdit < 0) {
 				cout << "This contact doesn't exist"  << endl;
 			} else {
	 			Person & p =  adressBook[posContactToEdit];

 				if(_name == adressBook[posContactToEdit].getName()){

			        int option = -1;
			        
			        do{
			        	cout << endl;

	 					cout << "Info to edit :"  << endl;
	 					cout << "\t1) Name"  << endl;
	 					cout << "\t2) Phone number"  << endl;
	 					cout << "\t3) Adress"  << endl;

	 					cout << endl;
	 					cin >> option;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			        	if (cin.fail() || (option != 1 && option != 2 && option != 3 ))
				        {
							cout << "\x1B[2J\x1B[H";
				            cout << "This is not an option..." << endl;
				        } 

					    if (option == 1) {

							cout << "New name : " << endl;
							getline (cin,_name);
							if(searchNamesake(_name) == 1){
								cout << endl << "Someone already have the same name, please choose another name"  << endl;
								option = -1;
							}else{
								p.setName(_name);
							}
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
	 					else{
	 						option = -1;
	 					}
			        }while (option < 0);
				        

 					cout << endl << "The contact had been edited" << endl;
 					p.printAll();
 				}

			}

		}

		void AdressBook::removeContact(){
			cout << "----------------------- SUPPRESSION D'UN CONTACT ----------------------"  << endl << endl;
			
			string _name;
			cout << "Contact to remove :"  << endl;
			getline (cin,_name);
 			cout << endl;
 			Person p = searchContact(_name);

			int position = searchContactPlace(p);
			if(position == -1){
				cout << "This contact doesn't exist and can't be removed" << endl << endl;
			}else{
				cout << "You are going to remove the contact : " << endl;
				p.printAll();
				adressBook.erase(adressBook.begin()+position);
				cout << "This contact had been removed" << endl << endl;
			}
			
		}

		void AdressBook::exportToFile(){
			cout << "----------------------- EXPORT CONTACTS ----------------------"  << endl << endl;
			ofstream myfile;
			myfile.open("AdressBook.txt");
			if (myfile.is_open()){
				vector<int>::size_type sz = adressBook.size();

				myfile << "\t MY CONTACTS\n\n";

				myfile  << sz << " CONTACTS\n\n";

 				for (unsigned i=0; i<sz; i++) {
					myfile << "CONTACT " << i+1 << ".\nName : ";

					myfile <<  adressBook[i].getName() << " \nPhone : " << adressBook[i].getPhoneNb();
					myfile << "\nAdress : ";
					myfile <<  adressBook[i].getAdress().getNumber() << " " << adressBook[i].getAdress().getStreet() << "\n\t";
					myfile <<  adressBook[i].getAdress().getZipCode() << " " << adressBook[i].getAdress().getCity() << "\n\t";
					myfile <<  adressBook[i].getAdress().getCountry();
					myfile << "\n\n";

 				}
				myfile.close();
				cout << "The contacts had been exported in the file \"AdressBook.txt\". "  << endl << endl;

			}
			else{
				cout << "Unable to open file";
			} 
		}


		void AdressBook::getContactFromFile(){ 
			
			const int LINE_RETURN = 10;
		    const int TWO_POINTS = 58;
		    const int SPACE = 32;
		    const int ZERO = 48;
		    const int POINT = 46;
			char car;
		    const int TAILLE_TAB = 30;

    		string line;
			ifstream myfile ("AdressBook.txt");

			if (myfile.is_open()){
				unsigned int nb = 0;
				unsigned int nbOfContacts = 0;

				while (myfile.get(car) && !(car >= ZERO && car <= ZERO + 9))
			    {} 
			    nbOfContacts = car - ZERO;

 				while ( myfile.get(car) && car != SPACE) {
			    	nbOfContacts = nbOfContacts*10 + (car - ZERO);
			    }

			    unsigned int j;
			    for (j = 0; j < nbOfContacts; j++) { 

					while ( myfile.get(car) && car != POINT)
				    { 
				    } 
				    
				    myfile.seekg (7, ios::cur); //go to name

				    
				    char tabChar[TAILLE_TAB];
				    myfile.get(car);

				    int i = 0;
				    while ( myfile.get(car) && car != LINE_RETURN) {
				    	tabChar[i] = car;
				    	i++;
				    }
				    string _name (tabChar, i-1);
	 				
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
	 				 nb = 0;
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
				}

				myfile.close();
			}
			
		}



		void AdressBook::print(){
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
 					cout << "Push a button to see the other contacts "  << endl << endl;
 					cin >> junk;
 					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					i--;
 					nbTest = 0;
 					cout << endl;
 				}
 				
			}
			cout << "-------------------------------------------------" << endl << endl;
		}
