#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool loginStatus(string,string);

int main(int argc, char** argv) {
	
	int choice;
	string username,password;
	
	system("cls");
	cout<<"\n\t\tMAIN PAGE";
	cout<<"\n========================================";
	cout<<"\n1. Register";
	cout<<"\n2. Login";
	cout<<"\n---> ";
	cin>>choice;
	
	if(choice == 1){
		system("cls");

		cout<<"\nREGISTRATION PAGE";
		cout<<"\n=================================";
		cout<<"\n\nEnter Username: ";	cin>>username;
		cout<<"Enter Password: "; cin>>password;
		
		ofstream File;
		File.open("data\\"+username+".txt");
		File << username <<endl << password;
		File.close();
		cout<<"\n\nAccount Created";
		getch();
	}
	
	else if(choice == 2){
		system("cls");
		cout<<"\nLOGIN PAGE";
		cout<<"\n=================================";
		cout<<"\n\nUsername: ";	cin>>username;
		cout<<"Password: "; cin>>password;
		
	if(loginStatus(username,password)){
		cout<<"\n\n\tWELCOME !!!!\n\n";
		system("PAUSE");
	}
	
	else{
		cout<<"\n\n\tWRONG CREDENTIAL";
	}
	
	getch();
		
	}
	
	
	main(argc, argv);
	
	return 0;
}

bool loginStatus(string username, string password){
	string un, ps;
	ifstream read("data\\"+username+".txt", ios::in);
	//File.read("data\\",ios::in);
	
	if(!read){
		cout<<"\nUser not found";
	}
	
	getline(read,un);
	getline(read,ps);
	
	if(un == username && ps == password){
		return true;
	}
	
	else{
		return false;
	}
}
