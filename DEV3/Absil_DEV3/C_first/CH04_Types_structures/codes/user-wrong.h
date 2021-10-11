#include "homedir-wrong.h"

typedef struct User
{
    char name[20];
    Homedir home;
} User; //typedef in one go

const char* who_is(User* u);