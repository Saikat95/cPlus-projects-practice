#include "Bank.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Account account;

void intro();
void menu_screen();

int main(int argc, char** argv) {
	
	intro();
	menu_screen();
	
	return 0;
}

void intro(){
	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t  ";	cout<<setw(30)<<setfill('-')<<"\n";
	cout<<"\n\n\t\t\t\t\t\t    Banking";
	cout<<"\n\n\t\t\t\t\t\t  Management";
	cout<<"\n\n\t\t\t\t\t\t    System";
	cout<<"n\n\n"<<"\t\t\t\t\t  "<<setw(30)<<setfill('-')<<"\n";
	cout<<"\n\n\t\t\t\t\t\t  Created By,";
	cout<<"\n\t\t\t\t\t\t  Saikat Guha";
	cout<<"\n\t\t\t\t\t\t	";
	
	cin.get();
	system("cls");
}

void menu_screen(){
	int menu_choice;
	bool menu_choice_true =  true;
	int search_accno;
	
	do{
	
	system("cls");
	
	cout<<"\n MAIN MENU";
	cout<<"\n---------------------------------------------------";
	cout<<"\n\n  01. CREATE ACCOUNT";
	cout<<"\n  02. DISPLAY ACCOUNT";
	cout<<"\n  03. DEPOSIT AMOUNT";
	cout<<"\n  04. WITHDRAW AMOUNT";
	cout<<"\n  05. MODIFY AN ACCOUNT";
	cout<<"\n  06. DISPLAY ALL ACCOUNT";
	cout<<"\n  07. DELETE AN ACCOUNT";
	cout<<"\n  08. DELETE ALL ACCOUNT";
	cout<<"\n  09. EXIT";
	cout<<"\n\n Select Your Option from <1-8>: "; cin>>menu_choice;
	
	system("cls");
		
	switch(menu_choice){
		case 1:
				write_account();
				//system("cls");
				break;
		case 2:
				cout<<"DISPLAY ACCOUNT DETAILS\n";
				cout<<"=================================\n";
				cout<<"\nEnter Account Number: ";	cin>>search_accno;
				show_details(search_accno);
				break;
		case 3:
				cout<<"\nEnter Account Number: ";	cin>>search_accno;
				deposit_withdraw(search_accno, 1);
				//system("cls");
				break;
		case 4:
				cout<<"\nEnter Account Number: ";	cin>>search_accno;
				deposit_withdraw(search_accno, 2);
				//system("cls");
				break;
		case 5:
				cout<<"\nEnter Account Number: "; 	cin>>search_accno;
				modify_details(search_accno);
				break;
		case 6:
				display_all();
				break;
		case 7: 
				cout<<"\nCLOSE ACCOUNT";
				cout<<"\n=============================";
				cout<<"\nEnter Account Number: "; cin>>search_accno;
				delete_account(search_accno);
				break;
		case 8:
				delete_all();
				break;
		case 9: 
				cout<<"Thank you for Banking with us";
				//system("cls");
				menu_choice_true = false;
				break;
		default:
				cout<<"\n\nINVALID CHOICE. PLEASE CHOOSE FROM <1-8>.";	
				break;
	}
	
	cin.ignore();
	cin.get();
	
	} while(menu_choice_true);
}
