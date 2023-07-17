#include "header.h"
#include "Pass.h"
#include "menu.h"

Pass userPass[1000];

int Pass::userCount(){
    int count = 0;
    ifstream ifs("UserPass.txt");
    string word;
    while(getline(ifs,word)){
        if(!word.empty()){
            count++;
        }
    }
    ifs.close();

    cout<<"t4";
    return count;
}

void Pass::newUserPass(){
    art();
    ofstream ofs("UserPass.txt", fstream::app);
    userPass[userCount()].id = userCount() + 1;
    string password;
    char c;
    gotoXY(40,20);
    cout << "\n\n\n\n\t  |\t\t\tID(DEFAULT): "<<userPass[userCount()].id;
	cout << "\n\t  |\t\t\tADD PASSWORD: ";

	while(c != '\r'){
        c = getch();
        if(c == 0){
            switch(getch()){
                default: break;
            }
        }

        else if(c == '\b'){
            if(password.size() != 0){
                cout<<"\b \b";
                password.erase(password.size() - 1, 1);
            }
            continue;
        }

        else if((c <=9 && c>=0) || (c<='z' && c>='a') || (c<='Z' && c>='A')){
            password += c;
            cout<<"*";
        }

        else{
            continue;
        }
	}

	strcpy(userPass[userCount()].password,password.c_str());


	ofs<<userPass[userCount()].id;
	ofs<<":";
	ofs<<userPass[userCount()].password;
	ofs<<endl;

	ofs.close();

	system("cls");

	adminMenu();
}

