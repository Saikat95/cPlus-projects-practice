#include "header.h"
#include "fstream.h"
#include "intro.h"
#include "admin.h"

int main(int argc, char** argv) {
	intro();
	char ch;
	do{
		int menu_choice;
		system("cls");
		cout<<"\n\n\n\t\tMAIN MENU";
		cout<<"\n\t\t=========================";
		cout<<"\n\t\t1. Book Issue";
		cout<<"\n\t\t2. Book Deposit";
		cout<<"\n\t\t3. Administrator Menu";
		cout<<"\n\t\t4. EXIT.";
		cout<<"\n\n\t\tChose from the option<1-4>: ";
		cin>>menu_choice;
		
		switch(menu_choice){
			case 1: issue_book(); break;
			case 2: deposit_book(); break;
			case 3: admin_menu(); break;
			case 4: exit(0);
			default: cout<<"\a\nInvalid Choice";
		}
		
	} while(ch != '4');
	
	return 0;
}
