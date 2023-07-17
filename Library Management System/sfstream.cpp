#include "header.h"
#include "fstream.h"
#include "Student.h"

Student student;
fstream sfile;

void write_student(){
	char ch;
	sfile.open("student.dat",ios::app | ios::out);
	do{
		system("cls");
		student.create_student();
		sfile.write(reinterpret_cast<char*>(&student), sizeof(Student));
		cout<<"\nStudent Added.";
		cout<<"\n\n\tDo you want to create another record(y/n): ";
		cin>>ch;
	} while(ch == 'y' || ch == 'Y');
	
	sfile.close();
}

void modify_student(){
	int found = 0;
	char search[6];
	system("cls");
	cout<<"Enter Roll Number of the Student: ";
	cin>>search;
	
	sfile.open("student.dat",ios::in | ios::out);
	while(sfile.read((char*)&student,sizeof(Student)) && found == 0){
		if(strcmpi(student.get_rollNo(),search) == 0){
			student.show_student();
			student.modify_student();
			int pos = -1*sizeof(student);
			sfile.seekp(pos,ios::cur);
			sfile.write(reinterpret_cast<char*>(&student),sizeof(Student));
			cout<<"\nRecord Updated.";
			found = 1;
		}
	}
	
	sfile.close();
	
	if(found == 0){
		cout<<"\nStudent Not found.";
	}
	getch();
}

void display_student(){
	int found = 0;
	char search[6];
	system("cls");
	
	cout<<"\nEnter Roll Number of Student: ";
	cin>>search;
	
	sfile.open("student.dat",ios::app | ios::in);
	
	while(sfile.read((char*)&student, sizeof(Student)) && found != 1){
		if(strcmpi(student.get_rollNo(),search) == 0){
			student.show_student();
			found = 1;
		}
	}
	
	sfile.close();
	if(found == 0){
		cout<<"\nStudent not found";
	}
	
	getch();
	
}

void delete_student(){
	int flag = 0;
	fstream tfile;
	char search[6];
	system("cls");
	
	cout<<"Enter Roll Number: ";
	cin>>search;
	sfile.open("student.dat", ios::app|ios::in);
	tfile.open("Temp.dat", ios::app | ios::in | ios::out);
	sfile.seekg(0,ios::beg);
	
	while(sfile.read((char*)&student, sizeof(Student))){
		if(strcmpi(student.get_rollNo(), search) != 0){
			tfile.write((char*)&student, sizeof(Student));
		}
		else{
			flag = 1;
		}
	}
	
	sfile.close();
	tfile.close();
	
	remove("student.dat");
	rename("Temp.dat", "student.dat");
	
	if(flag == 0){
		cout<<"\nStudent not found";
	}
	
	else{
		cout<<"\nStudent record Deleted";
	}
	
	getch();
}

void list_student(){
	sfile.open("student.dat");
	sfile.seekg(0,ios::beg);
	
	if(!sfile){
		cout<<"\nRecord not Found";
		getch();
		return;
	}
	
	cout<<"\n\n\t\t    STUDENT LIST\n";
	cout<<"\t==================================\n";
	cout<<"\t"<<setw(8)<<"Roll No."<<setw(15)<<"Student Name"<<setw(12)<<"Issued\n";
	cout<<"\t==================================\n";
	
	while(sfile.read((char*)&student, sizeof(Student))){
		student.report();
	}
	
	sfile.close();
	getch();
}
