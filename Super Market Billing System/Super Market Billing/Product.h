#include "header.h"

class Product{
    private:
        char pno[8];
        char name[20];
        float price, quantity, tax, discount;

    public:
        void create_product();
        void show_product() const;
        char* get_pno();
        char* get_name();
        float get_price();
        float get_quantity();
        float get_discount();
};
