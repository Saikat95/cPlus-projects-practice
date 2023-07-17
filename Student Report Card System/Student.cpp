#include "header.h"
#include "Student.h"

Student st;

void Student::create(){
	system("cls");
	cout<<"\n\nNEW STUDENT ENTRY";
	cout<<"\n===========================";
	cout<<"\nStudent Roll Number: ";
	cin>>rollNo;
	cout<<"Student Name: ";
	cin.ignore();
	cin.get(name,20);
	cout<<"Student Marks out of 100";
	cout<<"\n\tMaths: ";
	cin>>marks[0];
	cout<<"\tPhysics: ";
	cin>>marks[1];
	cout<<"\tChemistry: ";
	cin>>marks[2];
	cout<<"\tComputer Science: ";
	cin>>marks[3];
	cout<<"\tEnglish: ";
	cin>>marks[4];
	calculate();
	cout<<"\nStudent Created";
}

void Student::display() const{
	cout<<"\nRoll No.: "<<rollNo;
	cout<<"\nName: "<<name;
	cout<<"\nMarks in subjects";
	cout<<"\n 1. Mathematics: "<<marks[0];
	cout<<"\n 2. Physics: "<<marks[1];
	cout<<"\n 3. Chemistry: "<<marks[2];
	cout<<"\n 4. Computer Science: "<<marks[3];
	cout<<"\n 5. English: "<<marks[4];
	cout<<"\nPercentage: "<<percentage<<"%";
	cout<<"\nGrade: "<<grade;
	getch();
}

void Student::modify(){
	cout<<"\n\n MODIFY STUDENT";
	cout<<"\n===========================";
	cout<<"\nRoll Number: ";
	cin>>rollNo;
	cout<<"Name: ";
	cin.ignore();
	cin.get(name,20);
	cout<<"Student Marks out of 100";
	cout<<"\n\tMaths: ";
	cin>>marks[0];
	cout<<"\tPhysics: ";
	cin>>marks[1];
	cout<<"\tChemistry: ";
	cin>>marks[2];
	cout<<"\tComputer Science: ";
	cin>>marks[3];
	cout<<"\tEnglish: ";
	cin>>marks[4];
	calculate();
	cout<<"\nStudent Modified";

}

char* Student::get_rollNo(){
    return rollNo;
}

void Student::report(){
    cout<<setw(8)<<rollNo<<setw(10)<<name<<"     "<<setw(3)<<marks[0]<<"  "<<setw(6)<<marks[1]<<"    "<<setw(8)<<marks[2]<<"    "<<setw(8)<<marks[3]<<"    "<<setw(6)<<marks[4]<<"     "<<setw(4)<<percentage<<"    "<<setw(4)<<grade<<endl;
}
