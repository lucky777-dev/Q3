#include <stdio.h>
#include <string.h>

#include "homedir-fixed.h"
#include "user-fixed.h"

int main()
{
    HomeDir d = {"/home/abs"}; //explicit init
    User u = {"R. Absil"};
    
    d.user = u;
    u.home = &d;
    
    printf("%s\n", where_is(&d));
    printf("%s\n", who_is(&u));
}
