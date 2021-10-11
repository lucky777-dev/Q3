#ifndef HOMEDIR_H
#define HOMEDIR_H
#include "user-fixed.h"

typedef struct HomeDir
{
    char home[20];
    User user; //here, the alias exists
} HomeDir;

const char* where_is(HomeDir* d);
#endif