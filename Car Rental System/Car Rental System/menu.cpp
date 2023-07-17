#include "menu.h"
#include "header.h"
#include "Pass.h"
#include "Car.h"

Pass menuPass;
Car menuCar;

void fullscreen(){
 //system ("mode 1000");
 keybd_event(VK_MENU, 0x38, 0, 0);
 keybd_event(VK_RETURN, 0x1c, 0 , 0);
 keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
 keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void gotoXY(int x , int y){
    HANDLE handle;
    COORD coord;
    fflush(stdout);
    coord.X = x;
    coord.Y = y;

    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,coord);
}

void border() {
    int i;
    system("cls");
    for(i = 10; i<140; ++i){
        gotoXY(i,10);
        cout<<"=";
        gotoXY(i,58);
        cout<<"=";
    }
    for(i = 10; i<58; ++i){
        gotoXY(10,i);
        cout<<"|";
        gotoXY(140,i);
        cout<<"|";
    }

    cout<<"\n\n\n";
}

void load(){
    border();
    //int timer = 5 + rand()%50;
    int row, delay;
    gotoXY(65,34);
    cout<<"BOOTING SYSTEM";
    gotoXY(60,36);

    for(row = 1; row<=24; row++){
        for(delay=0; delay<=100000000 ; delay++);
        char i = 177;
        cout<<i;
    }

    Sleep(1000);

    system("cls");
}

void welcome(){
    border();
    gotoXY(25,25);
    fstream file("./img/welcome.txt");
    string lines = "";

    if(file){
        while(file.good()){
            string tempLine;
            getline(file,tempLine);
            tempLine += "\n\t  | ";

            lines += tempLine;
        }

        cout<<lines;
    }

    file.close();
    Sleep(1000);
}

void art(){

    border();

    fstream ifs;
    ifs.open("./img/art.txt");

    string lines = "";
    gotoXY(0,10);
    while(!ifs.eof()){
        string tempLines;
        getline(ifs,tempLines);
        tempLines += "\n";

        lines += tempLines;
    }

    cout<<lines;

    ifs.close();

    Sleep(1000);
}

void registrationPage(){

    int rpChoice;

    do{
    art();
    gotoXY(57,25);
    cout<<"     REGISTRATION PAGE";
    gotoXY(57,26);
    cout<<"==========================";
    gotoXY(62,28);
    cout<<"1. ADMIN LOGIN";
    gotoXY(62,29);
    cout<<"2. CUSTOMER LOGIN";
    gotoXY(62,30);
    cout<<"3. TERMS & CONDITION";
    gotoXY(62,32);
    cout<<">> ";
    cin>>rpChoice;

    switch(rpChoice){
        case 1: adminMenu();
                break;
        case 2:
                break;
        case 3: TnC();
                break;
        default: gotoXY(62,40);
                 cout<<"INVALID CHOICE";
    }

    } while(true);

}


void TnC(){
{
	art();
	cout<<endl;
	cout<<"\n\t  |\t\t\t1. MINIMUM RENT TIME IS 3 HOURS";
	cout<<"\n\t  |\t\t\t2. RISK BY YOUR OWN";
	cout<<"\n\t  |\t\t\t3. INCASE ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
	cout<<"\n\t  |\t\t\t4. PREPARE ITEM AS BELOW";
	cout<<"\n\t  |\t\t\t     \3COPY OF IC, LICENSE";
	cout<<"\n\t  |\t\t\t     \3DEPOSIT (BASED ON CAR TYPE)";
	cout<<"\n\t  |\t\t\t5. ADDITIONAL CHARGE IF LATE";
	cout<<"\n\t  |\t\t\t6. SAFE DRIVE!";
	cout<<"\n\n\n\n\t  |\t\t\t                             PRESS ANY KEY TO CONTINUE :)";
	cout<<"\n\t  |\t\t\t                                                            ";

	getch();
	registrationPage();
}
}

void userMenu(){
    int umChoice;
    do{
        art();
        gotoXY(57,25);
        cout<<"     USER PAGE";
        gotoXY(57,26);
        cout<<"==========================";
        gotoXY(62,28);
        cout<<"1. NEW USER";
        gotoXY(62,29);
        cout<<"2. EXISTING USER";
        gotoXY(62,30);
        cout<<"3. MAIN MENU";
        gotoXY(62,32);
        cout<<">> ";
        cin>>umChoice;

       switch(umChoice){
       case 1:
       case 2:
       case 3:
       default: gotoXY(62,40);
                cout<<"INVALID CHOICE";
       }

    } while(umChoice != 3);
}

void adminMenu(){
    int amChoice;

    do{
        art();
        	cout<<"\n\t  |\t\t\t\t\t\t\t  1. ADD ADMIN";
            cout<<"\n\t  |\t\t\t\t\t\t\t  2. SHOW DATA";
            cout<<"\n\t  |\t\t\t\t\t\t\t  3. ADD CAR";
            cout<<"\n\t  |\t\t\t\t\t\t\t  4. DELETE CAR";
            cout<<"\n\t  |\t\t\t\t\t\t\t  5. RESET AVAILABLE CAR";
            cout<<"\n\t  |\t\t\t\t\t\t\t  6. LOG OFF"<<endl<<"\n";
            cin>>amChoice;

            switch(amChoice){
                case 1: menuPass.newUserPass();
                        break;
                case 2: menuCar.showCarData();
                        break;
                case 3: menuCar.addNewCar();
                        break;
            }
    }while(amChoice != 6);
}
