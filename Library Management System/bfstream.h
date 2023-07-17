#include "header.h"
#include "fstream.h"
#include "Book.h"

Book book;
fstream bfile;

void write_book(){
	char ch;
	bfile.open("book.dat",ios::app | ios::out);
	do{
		system("cls");
		book.create_book();
		bfile.write((char*)&book, sizeof(Book));
		cout<<"\nBook Created;";
		cout<<"\n\tAdd another book(y/n): ";
		cin>>ch;
	} while(ch == 'y' || ch == 'Y');
	
	bfile.close();
}
