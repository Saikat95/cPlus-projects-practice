#include "header.h"
#include "Car.h"

Car rentCar[1000];
Car car;

int Car::countCar(){
    int count = 0;
    ifstream ifs("Rent Car.txt");
    string word;

    while(getline(ifs,word)){
        if(!word.empty()){
            count++;
        }
    }

    ifs.close();

    return count;
}

void Car::addNewCar(){
    ofstream ofs("Rent Car.txt",ios::app);

    int newCar = countCar() + 1;

    cout<<"\n\n  PLEASE ENTER THE CAR DETAILS BELOW ";
    cout<<"\n========================================";
    cout<<"\n\n Plate Number: ";
    cin.getline(rentCar[newCar].plate_num, 10);
    ofs <<rentCar[newCar].plate_num;
    ofs<<":";
    cout<<"\n Brand: ";
    cin.getline(rentCar[newCar].brand, 10);
    ofs <<rentCar[newCar].brand;
    ofs<<":";
    cout<<"\n Model: ";
    cin.getline(rentCar[newCar].model, 10);
    ofs <<rentCar[newCar].model;
    ofs<<":";
    cout<<"\n Capacity: ";
    cin>>rentCar[newCar].capacity;
    ofs <<rentCar[newCar].capacity;
    ofs<<":";
    cout<<"\n Color: ";
    cin>>ws;
    cin.getline(rentCar[newCar].color, 10);
    ofs <<rentCar[newCar].color;
    ofs<<":";
    cout<<"\n Rate per Hour: ";
    cin>>rentCar[newCar].rate_per_hour;
    ofs <<rentCar[newCar].rate_per_hour;
    ofs<<":";
    cout<<"\n Rate Per Day: ";
    cin>>rentCar[newCar].rate_per_day;
    ofs <<rentCar[newCar].rate_per_day;
    ofs<<":";
    cout<<"\n Transmission: ";
    cin>>ws;
    cin.getline(rentCar[newCar].transmission,10);
    ofs<<rentCar[newCar].transmission;

    ofs<<endl;

    system("cls");

    cout<<"\nNumber out: "<<newCar;
    //carData(newCar);
    getch();

    ofs.close();
}

void Car::showCarData(){

    cout << "\t  |  Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t  |  =========================================================================================================" << endl;

	ifstream ifs("Rent Car.txt");

	int i = 0;

       while(!ifs.eof()){
        ifs.getline(rentCar[i].plate_num,10,':');
        ifs.getline(rentCar[i].brand,10,':');
        ifs.getline(rentCar[i].model,10,':');
        ifs >> rentCar[i].capacity;
        ifs.ignore();
        ifs.getline(rentCar[i].color,10,':');
        ifs >> rentCar[i].rate_per_hour;
        ifs.ignore();
        ifs >> rentCar[i].rate_per_day;
        ifs.ignore();
        ifs.getline(rentCar[i].transmission,10);

         cout << "\t  |  " << rentCar[i].plate_num << "\t\t" << rentCar[i].brand << "\t " << rentCar[i].model << "\t   " << rentCar[i].capacity << "\t     "
			 << rentCar[i].color << "\t  " << rentCar[i].rate_per_hour << "\t\t    " << rentCar[i].rate_per_day
			 << "\t\t       " << rentCar[i].transmission <<endl;

        }

        ifs.close();
}

void Car::carData(int newCar){
    ifstream ifs;
    ifs.open("Rent Car.txt");
    int number = newCar;
    string line;

    while(!ifs.eof()){

        ifs.getline(rentCar[number].plate_num,10,':');
        cout<<"Plate Number: "<<rentCar[number].plate_num<<endl;

        ifs.getline(rentCar[number].brand,10,':');
        cout<<"Brand: "<<rentCar[number].brand<<endl;

        ifs.getline(rentCar[number].model,10,':');
        cout<<"Model: "<<rentCar[number].model<<endl;

        ifs>>rentCar[number].capacity;
        cout<<"Capacity: "<<rentCar[number].capacity<<endl;
        ifs.ignore();

        ifs.getline(rentCar[number].color,10,':');
        cout<<"Color: "<<rentCar[number].color<<endl;

        ifs>>rentCar[number].rate_per_hour;
        ifs.ignore();
        cout<<"Rate per Hour: "<<rentCar[number].rate_per_hour<<endl;

        ifs>>rentCar[number].rate_per_day;
        cout<<"Rate per Day: "<<rentCar[number].rate_per_day<<endl;
        ifs.ignore();

        ifs.getline(rentCar[number].transmission,10);
        cout<<"Transmission: "<<rentCar[number].transmission<<endl;

        cout<<"\n\n";
    }
    ifs.close();
}
