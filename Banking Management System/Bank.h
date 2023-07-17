#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<fstream>

using namespace std;

class Account{
	private:
		int acc_no;
		char name[50];
		double deposit_amount;
		char type;
		double balance = 0;

	public:
		void create_account(); //create account
		void display_account() const; //display account details
		void modify(); //add new data
		void deposit(double); //accept amount and add balance
		void withdraw(double); //accept amount and deduct balance
		int return_accno(); //return account number
		void report() const;	//return list of all accounts
};

//File streams functions
void write_account();
void deposit_withdraw(int,int);
void show_details(int);
void modify_details(int);
void display_all();
void delete_account(int);
void delete_all();
