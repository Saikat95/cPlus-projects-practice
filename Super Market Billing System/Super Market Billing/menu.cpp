#include "header.h"
#include "fstream.h"
#include "menu.h"

void intro(){
    system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t SUPER MARKET";
    cout<<"\n\n\t\t\t\t\t\t   BILLING";
    cout<<"\n\n\t\t\t\t\t\t   SYSTEM";

    cout<<"\n\n\n\t\t\t\t\t\tProject By,";
    cout<<"\n\t\t\t\t\t\tSaikat Guha";
    cout<<"\n\t\t\t\t\t\t  ";
    getch();
    main_menu();
}

void main_menu(){
    int mm_choice;

    do{
        system("cls");
        cout<<"\n\tMAIN MENU";
        cout<<"\n\t=============================";
        cout<<"\n\t1. Customer Menu";
        cout<<"\n\t2. Admin Menu";
        cout<<"\n\t3. Exit";
        cout<<"\n\tPlease enter your choice<1-3>: ";
        cin>>mm_choice;

        switch(mm_choice){
            case 1: customer_menu(); break;
            case 2: admin_menu(); break;
            case 3: intro(); break;
            default: cout<<"\n\t\tInvalid Choice";
                     getch();
        }

    } while(mm_choice != 3);
}

void customer_menu(){
    int cm_choice;

    do{
        system("cls");
        cout<<"\n\tCUSTOMER MENU";
        cout<<"\n\t===========================";
        cout<<"\n\t1. View Products";
        cout<<"\n\t2. Place Order";
        cout<<"\n\t3. Back to Main Menu";
        cout<<"\n\tPlease Enter you Choice<1-3>: ";
        cin>>cm_choice;

        switch(cm_choice){
            case 1: display_all(); break;
            case 2: list_products();
                    place_order();
                    getch();
                    break;
            case 3: main_menu(); break;
            default: cout<<"\n\tInvalid Choice";
                     getch();
        }
    } while(cm_choice != 3);
}

void admin_menu(){
    int am_choice;

    do{
        system("cls");
        cout<<"\n\tADMIN MENU";
        cout<<"\n\t==========================";
        cout<<"\n\t1. CREATE PRODUCT";
        cout<<"\n\t2. DISPLAY ALL PRODUCT";
        cout<<"\n\t3. SEARCH PRODUCT";
        cout<<"\n\t4. MODIFY PRODUCT";
        cout<<"\n\t5. DELETE PRODUCT";
        cout<<"\n\t6. DISPLAY ALL PRODUCTS";
        cout<<"\n\t7. BACK TO MAIN MENU";
        cout<<"\n\tPlease enter your choice<1-7>: ";
        cin>>am_choice;

        switch(am_choice){
            case 1: write_product(); break;
            case 2: display_all(); break;
            case 3: display_sp(); break;
            case 4: modify_product(); break;
            case 5: delete_product();break;
            case 6: list_products();break;
            case 7: main_menu(); break;
            default: cout<<"\n\tInvalid Choice";
                     getch();
        }
    } while(am_choice != 7);
}
