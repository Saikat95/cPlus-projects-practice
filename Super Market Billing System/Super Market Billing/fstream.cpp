#include "header.h"
#include "fstream.h"
#include "Product.h"

Product product;
fstream file;

void write_product(){
    char ch;
    file.open("product.dat", ios::app | ios::out);
    do{
        system("cls");
        product.create_product();
        file.write((char*)&product, sizeof(Product));
        cout<<"\nAdd more products(y/n)? ";
        cin>>ch;
    } while(ch == 'Y' || ch == 'y');

    cout<<"\nRecord Updated.";

    file.close();
}

void display_all(){
    system("cls");
    cout<<"DISPLAY ALL PRODUCTS";
    cout<<"\n=============================\n";
    file.open("product.dat", ios::app | ios::in);
    while(file.read((char*)&product, sizeof(Product))){
        product.show_product();
        cout<<"\n\n=================================";
    }
    file.close();
}

void display_sp(){
    char search[8];
    int found = 0;
    file.open("product.dat", ios::app | ios::in);

    system("cls");

    cout<<"\nDETAILS OF PRODUCT";
    cout<<"\n=============================\n";

    if(!file){
        cout<<"\nFile not found";
        return;
    }

    cout<<"\nEnter Product ID: ";
    cin>>search;


    while(file.read((char*)&product, sizeof(Product))){
        if(strcmpi(product.get_pno(), search) == 0){
            product.show_product();
            cout<<"\n---------------------------";
            found = 1;
        }
    }
    file.close();

    if(found == 0){
        cout<<"\nProduct not found";
    }

    getch();
}


void modify_product(){
    file.open("product.dat",ios::in | ios::out);
    char search[8];
    int found = 0;

    system("cls");

    cout<<"MODIFY RPODUCT";
    cout<<"\n===========================\n";
    cout<<"\nEnter Product ID: ";
    cin>>search;

    while(file.read((char*)&product, sizeof(Product))){
        if(strcmpi(product.get_pno(), search) == 0){
            product.show_product();
            cout<<"\n=============================\n";
            cout<<"\n\nEDIT ITEM\n";
            product.create_product();
            int pos = -1*sizeof(product);
            file.seekp(pos,ios::cur);
            file.write((char*)&product, sizeof(Product));
            found = 1;
            cout<<"\nRecord Updated";
        }
    }

    file.close();

    if(found == 0){
        cout<<"\nRecord not found";
    }
}

void delete_product(){
    system("cls");
    char search[8];
    int found = 0;
    file.open("product.dat", ios::app | ios::in);

    if(!file){
        cout<<"\nFile not found";
        return;
    }

    cout<<"\nEnter product Number: ";
    cin>>search;

    fstream tfile;
    tfile.open("temp.dat", ios::app | ios::in | ios::out);

    file.seekg(0,ios::beg);

    while(file.read((char*)&product, sizeof(Product))){
        if(strcmpi(product.get_pno(), search) != 0){
            tfile.write((char*)&product, sizeof(Product));
            found = 1;
        }
    }

    file.close();
    tfile.close();

    remove("product.dat");
    rename("temp.dat","product.dat");


    if(found == 0){
        cout<<"\nRecord not found to delete";
    }
    else{
        cout<<"\nRecord Deleted";
    }
}

void list_products(){
    system("cls");

    file.open("product.dat", ios::app | ios::in);

    if(!file){
        cout<<"\n\tFile not found";
    }
    cout<<"\n\tLIST OF PRODUCTS\n";
    cout<<"======================================\n";
    cout<<" P.No."<<"  "<<"Product Name"<<"  "<<"Price"<<"  "<<"Discount";
    cout<<"\n======================================\n";
    while(file.read((char*)&product, sizeof(Product))){
        cout<<setw(5)<<product.get_pno()<<"  "<<setw(12)<<product.get_name()<<"  "<<setw(5)<<product.get_price()<<"  "<<setw(8)<<product.get_discount()<<endl;
    }
    cout<<"======================================\n";

    file.close();

    getch();
}

void place_order(){
    char order_arr[50][10];
    int order_qty[50];
    char ch;
    int count = 0;

    cout<<"\n\tPLACE ORDER";
    cout<<"\n==========================\n";
    do{
        cout<<"\nEnter Product Id: ";
        cin>>order_arr[count];
        cout<<"\nEnter Quantity: ";
        cin>>order_qty[count];
        count++;
        cout<<"\nAdd more items(y/n)?";
        cin>>ch;
    } while(ch == 'y' || ch == 'Y');

    cout<<"\n-------Thank You for Placing orders--------\n";
    getch();

    system("cls");

    float amount, damount, total = 0;



    cout<<"\nP.No."<<" "<<"P.Name"<<" "<<"Price"<<" "<<"Quantity"<<" "<<"D.Amount";
    cout<<"\n=========================================\n";

    for(int i=0; i<count; ++i){

    file.open("product.dat", ios::app | ios::in);
    file.read((char*)&product, sizeof(Product));

    while(!file.eof()){
        if(strcmpi(order_arr[i], product.get_pno()) == 0){
            amount = product.get_price() * order_qty[i];
            damount = amount - ((product.get_discount()/100) * amount);
            cout<<setw(5)<<product.get_pno()<<" "<<setw(6)<<product.get_name()<<" "<<setw(5)<<product.get_price()<<" "<<setw(8)<<order_qty[i]<<" "<<setw(8)<<damount<<endl;
            total += damount;
    }
    file.read((char*)&product, sizeof(Product));
    }

    file.close();
    }


    cout<<"\n========================================";
    cout<<"\n\n\tTOTAL: "<<total<<"\n";

}
