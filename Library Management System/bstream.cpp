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
		cout<<"\nBook Created.";
		cout<<"\n\tAdd another book(y/n): ";
		cin>>ch;
	} while(ch == 'y' || ch == 'Y');
	
	bfile.close();
}

void modify_book(){
	char search[6];
	int found = 0;
	system("cls");
	cout<<"\nEnter Book Number to search: ";
	cin>>search;
	
	bfile.open("book.dat",ios::in|ios::out);
	
	while(bfile.read((char*)&book,sizeof(Book)) && found == 0){
		if(strcmpi(book.get_bookNo(),search) == 0){
			book.show_book();
			book.modify_book();
			int pos = -1*sizeof(book);
			bfile.seekp(pos,ios::cur);
			bfile.write((char*)&book,sizeof(Book));
			cout<<"\nRecord Updated";
			found = 1;
		}
	}
	bfile.close();
	if(found == 0){
		cout<<"\nBook not found.";
	}
	
	getch();
}

void display_book(){
	int found = 0;
	char search[6];
	system("cls");
	cout<<"Enter Book Number: ";
	cin>>search;
	
	bfile.open("book.dat", ios::app | ios::in);
	
	while(bfile.read((char*)&book, sizeof(Book)) && found != 1){
		if(strcmpi(book.get_bookNo(), search) == 0){
			book.show_book();
			found = 1;
		}
	}
	
	bfile.close();
	
	if(found == 0){
		cout<<"\nRecord not found.";
	}
	
	getch();
	
}

void delete_book(){
	int flag = 0;
	fstream tfile;
	char search[6];
	system("cls");
	
	cout<<"\nEnter Book Number: ";
	cin>>search;
	
	bfile.open("book.dat",ios::app | ios::in);
	tfile.open("Temp.dat",ios::app | ios::in | ios::out);
	bfile.seekg(0,ios::beg);
	
	while(bfile.read((char*)&book, sizeof(Book))){
		if(strcmpi(book.get_bookNo(), search) !=0){
			tfile.write((char*)&book,sizeof(Book));
		}
		else{
			flag = 1;
		}
	}
	
	bfile.close();
	tfile.close();
	
	remove("book.dat");
	rename("Temp.dat", "book.dat");
	
	if(flag == 1){
		cout<<"\nRecord Deleted";
	}
	else{
		cout<<"\nBook Number not found";
	}
	
	getch();
	
}

void list_book(){
	bfile.open("book.dat",ios::in);
	bfile.seekg(0,ios::beg);
	
	if(!bfile){
		cout<<"\nFile not found";
		getch();
		return;
	}
	
	cout<<"\n\n\t\t\tBOOK LIST";
	cout<<"\n\t=======================================\n";
	cout<<"\t"<<setw(8)<<"Book No."<<setw(15)<<"Book Name"<<setw(15)<<"Author Name";
	cout<<"\n\t=======================================\n";
	
	while(bfile.read((char*)&book, sizeof(Book))){
		book.report();
	}
	
	bfile.close();
	
	getch();
}
