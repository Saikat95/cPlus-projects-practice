#include "header.h"
#include "Product.h"

void Product::create_product(){
    cout<<"\nProduct ID: ";
    cin>>pno;
    cout<<"Product Name: ";
    cin.ignore();
    cin.get(name,20);
    cout<<"Product Price: ";
    cin>>price;
    cout<<"Discount on Product: ";
    cin>>discount;
    getch();
}

void Product::show_product() const{
    cout<<"\nProduct ID: ";
    cout<<pno;
    cout<<"\nProduct Name: ";
    cout<<name;
    cout<<"\nProduct Price: ";
    cout<<price;
    cout<<"\nProduct Discount: ";
    cout<<discount;
    getch();
}

char* Product::get_pno(){
    return pno;
}

char* Product::get_name(){
    return name;
}

float Product::get_price(){
    return price;
}

float Product::get_discount(){
    return discount;
}
