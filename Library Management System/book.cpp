#include "header.h"
#include "Book.h"

char* Book::get_bookNo(){
	return bookNo;
}

char* Book::get_bookName(){
	return bookName;
}

char* Book::get_authorName(){
	return authorName;
}

void Book::create_book(){
	cout<<"\nNEW BOOK ENTRY";
	cout<<"\nEnter Book Number: ";
	cin>>bookNo;
	cin.ignore();
	cout<<"Enter Book Name: ";
	cin.get(bookName,20);
	cin.ignore();
	cout<<"Enter Author Name: ";
	cin.get(authorName,20);
}

void Book::show_book() const {
	cout<<"\nBook No: ";
	cout<<bookNo;
	cout<<"\nBook Name: ";
	cout<<bookName;
	cout<<"\nAuthor Name: ";
	cout<<authorName;
}

void Book::modify_book() {
	bool retry = false;
	cout<<"\n\nMODIFY DETAILS OF BOOK";
	do{
		int modify_choice;
		
		cout<<"\nWhat you want to modify? ";
		cout<<"\n1. Book Number";
		cout<<"\n2. Book Name";
		cout<<"\n3. Auhor Name";
		cout<<"\n4. Exit.";
		cout<<"\nSelect from option <1-4>: ";	cin>>modify_choice;
		
		switch(modify_choice){
			case 1: cout<<"\nBook Number: ";
					cin>>bookNo;
					retry = false;
					break;
			case 2: cout<<"\nBook Name: ";
					cin.ignore();
					cin.get(bookName,20);
					retry = false;
					break;
			case 3: cout<<"\nAuthor Name: ";
					cin.ignore();
					cin.get(authorName,20);
					retry = false;
					break;
			case 4: cout<<"Nothing Modified";
					retry = false;
					break;	
			default: cout<<"Invalid Choice";
						retry = true;
		}		
	} while(retry);
}

void Book::report(){
	cout<<"\t"<<setw(7)<<bookNo<<setw(15)<<bookName<<setw(15)<<authorName<<endl;
}
