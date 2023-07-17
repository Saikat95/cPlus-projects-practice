#include "menu.h"
#include "filestream.h"

void intro(){
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t   STUDENT";
	cout<<"\n\n\t\t\t\t\t\tREPORT  CARD";
	cout<<"\n\n\t\t\t\t\t\t   PROJECT";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t  MADE BY,";
	cout<<"\n\t\t\t\t\t\tSaikat Guha";
	cout<<"\n\n\t\t\t\t\t\t    ";
	getch();
	main_menu();
}

void main_menu(){
	system("cls");
	int mm_choice;
	
	do{
		cout<<"\n\tMAIN MENU";
		cout<<"\n\t01. RESULT MENU";
		cout<<"\n\t02. EDIT/ENTRY MENU";
		cout<<"\n\t03. EXIT";
		
		cout<<"\n\n\tPlease select your option <1-3>: ";
		cin>>mm_choice;
		
		switch(mm_choice){
			case 1: result_menu();	break;
			case 2: edit_menu();	break;
			case 3: intro(); break;
			default: cout<<"\a\n\t\tINVALID CHOICE";
		}
	} while(mm_choice != 3);
}

void edit_menu(){
	system("cls");
	int em_choice;
	
	
	do{	
		system("cls");
		cout<<"\n\tEDIT MENU";
		cout<<"\n\t01. CREATE STUDENT RECORD";
		cout<<"\n\t02. DISPLAY ALL STUDENTS";
		cout<<"\n\t03. SEARCH STUDENT RECORD";
		cout<<"\n\t04. MODIFY STUDENT RECORD";
		cout<<"\n\t05. DELETE STUDENT RECORD";
		cout<<"\n\t06. BACK TO MAIN MENU";
		
		cout<<"\n\n\tPlease select your choice<1-6>: ";
		cin>>em_choice;
		
		switch(em_choice){
			case 1: write_student(); break;
			case 2: display_all(); break;
			case 3: display_sp_student(); break;
			case 4: modify_student(); break;
			case 5: delete_student(); break;
			case 6: main_menu(); break;
			default: cout<<"\aINVALID CHOICE";
		}
		 
		}while(em_choice != 6);
}

void result_menu(){
	system("cls");
	int rm_choice;
	
	do{
		system("cls");
		cout<<"\n\tRESULT MENU";
		cout<<"\n\t01. CLASS RESULT";
		cout<<"\n\t02. STUDENT REPORT CARD";
		cout<<"\n\t03. BACK TO MAIN MENU";
		
		cout<<"\n\n\tPlease select your choice<1-3>: ";
		cin>>rm_choice;
		
		switch(rm_choice){
			case 1: list_student(); break;
			case 2: cout<<"\nSTUDENT REPORT CARD";
					display_sp_student(); 
					break;
			case 3: main_menu(); break;
			default: cout<<"\aINVALID CHOICE";
		}
	} while(rm_choice != 3);
}
