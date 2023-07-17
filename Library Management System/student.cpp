#include "header.h"
#include "Student.h"

char* Student::get_rollNo(){
	return rollNo;
}

char* Student::get_studentName(){
	return studentName;
}

char* Student::get_studentBookNo(){
	return studentBookNo;
}

void Student::set_studentBookNo(char t[]){
	strcpy(studentBookNo,t);
}

int Student::get_token(){
	return token;
}

void Student::add_token(){
	token = 1;
}

void Student::reset_token(){
	token = 0;
}

void Student::create_student(){
	cout<<"\nNEW STUDENT ENTRY";
	cout<<"\nEnter Student Roll No.: ";
	cin>>rollNo;
	cout<<"Enter Student Name: ";
	cin.ignore();
	cin.get(studentName,20);
	//gets(studentName);
	token = 0;
	studentBookNo[0] = '\0';
}

void Student::show_student(){
	cout<<"\nStudent Roll No.: ";
	cout<<rollNo;
	cout<<"\nStudent Name: ";
	cout<<studentName;
	cout<<"\nNumber of Books Issued: ";
	cout<<token;
	if(token == 1){
		cout<<"\nBook Number: ";
		cout<<studentBookNo;
	}
}

void Student::modify_student(){
	bool retry = false;
	cout<<"\n\nMODIFY STUDENT DETAILS";
	do{
		int modify_choice;
		
		cout<<"\nWhat do you want to modify?";
		cout<<"\n1. Modify Roll No.";
		cout<<"\n2. Modify Name";
		cout<<"\n3. Exit";
		cout<<"\nSelect from the option<1-3>: ";
		cin>>modify_choice;
		
		switch(modify_choice){
			case 1: cout<<"\nEnter Roll No.: ";
					cin>>rollNo;
					retry = false;
					break;
			case 2: cout<<"\nEnter Name: ";
					cin.ignore();
					cin.get(studentName,20);
					//gets(studentName);
					retry = false;
					break;
			case 3: cout<<"\nNothing Modified.";
					retry = false;
					break;
			default: cout<<"\nInvalid Choice";
						retry = true;		
		}} while(retry);
}

void Student::report(){
	cout<<"\t"<<setw(8)<<rollNo<<setw(15)<<studentName<<setw(12)<<studentBookNo<<endl;
}
