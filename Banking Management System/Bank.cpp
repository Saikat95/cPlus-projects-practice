#include "bank.h"

using namespace std;

void Account::create_account(){
	cout<<"\nEnter Account Number: ";
	cin>>acc_no;
	cout<<"\nEnter Account Holder Name: ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter the type of Account(C/S): ";
	cin>>type;
	type = toupper(type);
	cout<<"\nEnter the initial amount(>500) if Saving account and (>1000) if Current account: ";
	cin>>deposit_amount;
	balance = 0;
	balance += deposit_amount;
	cout<<"\nAccount Created.";
}

void Account::display_account() const{
	cout<<"\nAccount Number: "<<acc_no;
	cout<<"\nAccoount Holder Name: "<<name;
	cout<<"\nAccount Type: ";
	if(type == 'S') cout<<"Saving";
	else cout<<"Current";
	cout<<"\nBalance: "<<balance;
	cout<<endl;
}

void Account::modify(){
	
	bool modifyIsNotValid = false;
	
	do{
		cout<<"\n\nWhat do want to modify: ";
		cout<<"\n	1. Account Number.";
		cout<<"\n	2. Name.";
		cout<<"\n	3. Account Type.";
	
		int modify_choice;
		
		cout<<"\nPlease choose an option(1,2,3): ";
		cin>>modify_choice;
	
		switch(modify_choice){
		
		case 1:
			int new_acc_no;
			cout<<"\n	Enter new Account Number: "; cin>>new_acc_no;
			acc_no = new_acc_no;
			modifyIsNotValid = false;
			break;
			
		case 2:
			cout<<"\n	Enter new Name: "; cin>>name;
			modifyIsNotValid = false;
			break;
			
		case 3: 
			cout<<"\n	Enter Account type(S/C): "; cin>>type;
			type = toupper(type);
			modifyIsNotValid = false;
			break;
			
		default:
			cout<<"\n		Invalid Choice. Please choose from the options: ";
			modifyIsNotValid = true;
		}
		
	} while(modifyIsNotValid);
	
}

void Account::report() const {
	cout<<"\t"<<setfill(' ')<<setw(10)<<acc_no<<setw(10)<<name<<setw(6)<<type<<setw(12)<<balance<<endl;
}

void Account::deposit(double x){
	balance += x;
}

void Account::withdraw(double x){
	balance -= x;
}

int Account::return_accno(){
	return acc_no;
}


