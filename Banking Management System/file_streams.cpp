#include "Bank.h"

Account ac;

void write_account(){
	ofstream outFile;
	outFile.open("account.dat", ios::app | ios::binary);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	outFile.close();
}

void deposit_withdraw(int n, int option){
	double amount;
	bool found = false;
	
	fstream File;
	File.open("account.dat",  ios::binary|ios::in|ios::out);
	
	if(!File){
		cout<<"File couldn't be found. Press any key..";
		return;
	}
	
	while(!(File.eof() && found == false)){
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
			if(ac.return_accno() == n){
				ac.display_account();
				
				if(option == 1){
					cout<<"\nDEPOSIT AMOUNT";
					cout<<"\nEnter Amount: ";
					cin>>amount;
					ac.deposit(amount);
					
				}
				
				if(option == 2){
					cout<<"\nWITHDRAW AMOUNT";
					cout<<"\nEnter Amount: ";
					cin>>amount;
					ac.withdraw(amount);
				
				}
				int pos = (-1) * static_cast<int>(sizeof(ac));
				File.seekp(pos,ios::cur);
				File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
				found = true;
				break;
			}
		}
			File.close();
			if(found == false){
			cout<<"Record not found";
	}
}

void show_details(int n){
	bool flag = false;
	ifstream File;
	File.open("account.dat",ios::binary|ios::out);
	if(!File){
		cout<<"\nCouldn't open specified file";
		return;
	}
	
	cout<<"\nACCOUNT STATUS";
	cout<<"\n-------------------------------";
	while(File.read(reinterpret_cast<char*> (&ac), sizeof(Account))){
		if(ac.return_accno() == n){
			ac.display_account();
			flag = true;
		}
	}
	File.close();
	
	if(flag == false){
		cout<<"\nAccount number not available";
	}
}

void modify_details(int n){
	bool found = false;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"\nCan't open the file";
		return;
	}
	
	while(!File.eof() && found == false){
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.return_accno() == n){
			ac.display_account();
			cout<<"\nModify details for Account Number: "<<n;
			ac.modify();
				int pos = (-1) * static_cast<int>(sizeof(Account));
				File.seekp(pos,ios::cur);
				File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
				found = true;
				cout<<"\nRecord Updated";
		}
	}
	File.close();
	if(found == false){
		cout<<"\nAccount number not found";
	}
}

void display_all(){
	ifstream File;
	File.open("account.dat", ios::binary);
	if(!File){
		cout<<"\nFile not found";
		return;
	}
	cout<<"\n\n\t\t  Account Holder List";
	cout<<"\n\t==========================================";
	cout<<"\n\tAccount No.     Name   Type     Balance";
	cout<<"\n\t==========================================\n";
	while(File.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
		ac.report();
	}
	File.close();
}

void delete_account(int n){
	ifstream iFile;
	ofstream oFile;
	iFile.open("account.dat",ios::binary);
	if(!iFile){
		cout<<"\nFile not found..!!";
		return;
	}
	
	oFile.open("Temp.dat",ios::binary);

	while(iFile.read(reinterpret_cast<char*> (&ac), sizeof(Account))){
		if(ac.return_accno() != n ){
			oFile.write(reinterpret_cast<char*> (&ac), sizeof(Account));
		}
	}
	iFile.close();
	oFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\nRecord Deleted";
}

void delete_all(){
	//ifstream File;
	//File.open("account.dat", ios::binary);
	/*
	if(!File){
		cout<<"\nError deleting the record. Please try again";
		return;
	}
	*/
	
	remove("account.dat");
	//File.close();
	cout<<"\n\nAll records deleted";
	
}
