#include "user-wrong.h"

typedef struct HomeDir
{
    char home[20];
    User user;
} HomeDir; //typedef in one go

const char* where_is(HomeDir* d);