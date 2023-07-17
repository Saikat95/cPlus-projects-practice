#include "header.h"

void admin_menu(){
	system("cls");
	int menu_choice;
	cout<<"\n\t   ADMINISTRATOR MENU";
	cout<<"\n     =============================";
	cout<<"\n\t1. CREATE STUDENT";
	cout<<"\n\t2. DISPLAY ALL STUDENTS";
	cout<<"\n\t3. DISPLAY SPECIFIC STUDENT";
	cout<<"\n\t4. MODIFY STUDENT RECORD";
	cout<<"\n\t5. DELETE STUDENT RECORD";
	cout<<"\n\t6. CREATE BOOK";
	cout<<"\n\t7. DISPLAY ALL BOOKS";
	cout<<"\n\t8. DISPLAY SPECIFIC BOOK";
	cout<<"\n\t9. MODIFY BOOK";
	cout<<"\n\t10. DELETE BOOK";
	cout<<"\n\t11. BACK TO MAIN MENU";
	cout<<"\n\n      Please select you choice<1-11>: ";
	cin>>menu_choice;
	
	system("cls");
	
	switch(menu_choice){
		case 1: write_student(); break;
		case 2: list_student(); break;
		case 3: display_student(); break;
		case 4: modify_student(); break;
		case 5: delete_student(); break;
		case 6: write_book(); break;
		case 7: list_book(); break;
		case 8: display_book(); break;
		case 9: modify_book(); break;
		case 10: delete_book(); break;
		case 11: return;
		default: cout<<"\a";
				 cout<<"Invalid Input.";
	}
	
	admin_menu();
}
