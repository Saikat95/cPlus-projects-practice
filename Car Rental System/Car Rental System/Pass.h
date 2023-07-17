#include "header.h"

class Pass{
private:
    int id;
    char password[20];

public:
    void newUserPass();
    int userCount();
    void readUserPass();
};
