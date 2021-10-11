#ifndef USER_H
#define USER_H

//no include here

struct HomeDir; //anticipated declaration

typedef struct User
{
    char name[20];
    struct HomeDir* home; //here, no alias is defined
} User; 

const char* who_is(User* u);
#endif