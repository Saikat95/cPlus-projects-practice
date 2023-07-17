#include "header.h"
#include "fstream.h"
#include "Book.h"
#include "Student.h"

Book bk;
Student st;

fstream sf;
fstream bf;

void issue_book(){
	int found = 0, flag = 0;
	char sstudent[6];
	char sbook[6];
	
	system("cls");
	
	cout<<"\nBOOK ISSUE";
	cout<<"\nEnter Student Roll Number: ";
	cin>>sstudent;
	
	sf.open("student.dat", ios::in | ios::out);
	bf.open("book.dat", ios::in | ios::out);
	
	while(sf.read((char*)&st, sizeof(Student)) && found == 0){
		if(strcmpi(st.get_rollNo(),sstudent) == 0){
			found = 1;
			if(st.get_token() == 0){
				cout<<"\nEnter book Number: ";
				cin>>sbook;
				
				while(bf.read((char*)&bk, sizeof(bk)) && flag == 0){
					if(strcmpi(bk.get_bookNo(),sbook) == 0){
						bk.show_book();
						st.set_studentBookNo(bk.get_bookNo());
						st.add_token();
						int pos = -1*sizeof(st);
						sf.seekp(pos, ios::cur);
						sf.write((char*)&st, sizeof(Student));
						cout<<"\n\nBook Issued";
						cout<<"\n Note: Please return the book with 15days. Re.1 fine willbe collected after 15 days.";
						flag = 1;
					}
				}
				if(flag == 0){
					cout<<"\nBook not found";
				}
			}
			else{
				cout<<"\nYou have not returned last book";
			}
		}
	}
	
	if(found == 0){
		cout<<"\nStudent Not Found";
	}
	
	sf.close();
	bf.close();
	
	getch();
	
	return;
}

void deposit_book(){
	int found = 0, flag = 0;
	char sstudent[6];
	char sbook[6];
	int fine ,days;
	
	system("cls");
	
	cout<<"\nBOOK DEPOSIT";
	cout<<"\nEnter Student Roll Number: ";
	cin>>sstudent;
	
	sf.open("student.dat", ios::in | ios::out);
	bf.open("book.dat", ios::in | ios::out);
	
	while(sf.read((char*)&st, sizeof(Student)) && found == 0){
		if(strcmpi(st.get_rollNo(),sstudent) == 0){
			found = 1;
			if(st.get_token() == 1){
				
				cout<<"\nNo. of days book kept: ";
				cin>>days;
				
				if(days>15){
					fine = (days-15) * 1;
					cout<<"\nPlease deposit a fine of Rs. "<<fine;
					getch();
				}
						st.reset_token();
						int pos = -1*sizeof(st);
						sf.seekp(pos, ios::cur);
						sf.write((char*)&st, sizeof(Student));
						cout<<"\n\nBook Deposited";
						flag = 1;
					}
					
				else{
				cout<<"\nYou have no book to return.";
				}
			}
			
	}
	
	if(found == 0){
		cout<<"\nStudent Not Found";
	}
	
	sf.close();
	bf.close();
	
	getch();
	
	return;
}
