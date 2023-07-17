#include "header.h"
#include "filestream.h"
#include "Student.h"

fstream file;
Student student;

void write_student(){
    file.open("student.dat", ios::app | ios::in | ios::out);
    char ch;

    do{
        system("cls");
        student.create();
        file.write((char*)&student, sizeof(Student));
        cout<<"\nAdd another student(y/n)?: ";
        cin>>ch;
    } while(ch == 'y' || ch == 'Y');

    file.close();
}

void display_all(){
	system("cls");
	file.open("student.dat", ios::app | ios::in);
	cout<<"\nALL STUDENTS";
	cout<<"\n=========================";
	while(file.read((char*)&student, sizeof(Student))){
		student.display();
		cout<<"\n====================================================\n";
	}
	file.close();
}

void display_sp_student(){
	system("cls");
	char search[6];
	int found = 0;
	
	file.open("student.dat",ios::app | ios::in | ios::out);
	system("cls");
	if(!file){
		cout<<"\nError fetching the file";
	}
	cout<<"\nEnter roll number: ";
	cin>>search;
	
	while(file.read((char*)&student, sizeof(Student)) && found == 0){
		if(strcmpi(student.get_rollNo(),search) == 0){
			cout<<"\nDetails of Student";
			cout<<"\n================================";
			student.display();
			found = 1;
		}
	}
	file.close();
	
	if(found == 0){
		cout<<"\nStudent not found";
	}
}

void modify_student(){
	system("cls");
	char search[6];
	int found = 0;
	
	file.open("student.dat", ios::in | ios::out);
	

	
	if(!file){
		cout<<"\nFile not found";
	}
	
	cout<<"\nEnter Roll Number: ";
	cin>>search;
	
	while(file.read((char*)&student, sizeof(student)) && found == 0){
		if(strcmpi(student.get_rollNo(),search) == 0){
			cout<<"\nDetails of Student: "<<student.get_rollNo();
			student.display();
			cout<<"\n\n============================";
			student.modify();
			int pos = (-1)*sizeof(student);
			file.seekp(pos,ios::cur);
			file.write((char*)(&student),sizeof(Student));
			found = 1;
		}
	}
	
	file.close();
	
	if(found == 0){
		cout<<"\nStudent record not found";
	}
}

void list_student(){
	system("cls");
	file.open("student.dat", ios::in);
	
	if(!file){
		cout<<"\nFile not found.";
		return;
	}
	
	cout<<"\n\t\t\t\t CLASS RESULT";
	cout<<"\n========================================================================================";
	cout<<"\n"<<"Roll No. "<<setw(10)<<"Name "<<"    "<<"Math   "<<"Physics   "<<"Chemistry   "<<"C.Science   "<<"English   "<<"Perc.   "<<"Grade ";
	cout<<"\n========================================================================================\n";
		
	while(file.read((char*)&student, sizeof(Student))){
	
		student.report();
	}
	
	cout<<"\n========================================================================================\n";
	
	file.close();
	
	getch();
}

void delete_student(){
	fstream tfile;
	
	file.open("student.dat", ios::app | ios::in | ios::out);
	tfile.open("temp.dat", ios::app | ios::in | ios::out);
	
	char search[6];
	int found = 0;
	
	cout<<"\nEnter Roll No.: ";
	cin>>search;
	
	file.seekg(0, ios::beg);
	
	while(file.read((char*)&student, sizeof(Student))){
		if(strcmpi(student.get_rollNo(),search) != 0){
			tfile.write((char*)&student , sizeof(student));
		}
		else{
			found = 1;
		}
	}
	

	file.close();
	tfile.close();
	remove("student.dat");
	rename("temp.dat", "student.dat");


	if(found == 1){
		cout<<"\nRecord Deleted";
	}
	else{
		cout<<"\nRecord Not Found";
	}
	
	getch();
}
