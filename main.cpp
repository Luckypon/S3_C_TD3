
#include "adress.h"
#include "person.h"
#include "adressBook.h"




class Menu { 

	private:
    AdressBook & book;
    void main_screen()
    {
    
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
    /*Here we check if input is correct.*/
    int input()
    {
        int option = -1;
        cin >> option;
        cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (cin.fail() || (option != 0 && option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6))
        {
			cout << "\x1B[2J\x1B[H";
            cout << "This is not an option..." << endl;
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


            if (option == 1) {
	  			book.print();
			} 
			else  if (option == 2) {
				book.searchContact();
			} 
			else  if (option == 3) { 
				book.addContact();
			} 
			else  if (option == 4) {
   				book.removeContact();
			}
			else  if (option == 5) {
  				book.editContact();
			}
			else  if (option == 6) {
				book.exportToFile();
			}

        } while (option != 0);

    }

};


int main () {
	AdressBook book;
	book.getContactFromFile();

	Menu menu(book);
	menu.start();

	return 0;
}