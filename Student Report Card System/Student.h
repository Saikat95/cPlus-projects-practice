#include "header.h"

class Student {
	private:
		char rollNo[6];
		char name[20];
		double marks[5];
		double percentage;
		char grade;
		void calculate(){
			int sum = 0;
	for(int i =0; i<5; i++){
		sum += marks[i];
	}

	percentage = sum/5;

	if(percentage>=80){
		grade = 'A';
	}

	else if(percentage>=70){
		grade = 'B';
	}

	else if(percentage>=60){
		grade = 'C';
	}

	else if(percentage>=50){
		grade = 'D';
	}
	else if(percentage>=40){
		grade = 'E';
	}
	else{
		grade = 'F';
	}
}

	public:
	    char* get_rollNo();
		void create();
		void display() const;
		void modify();
		void report();
};
