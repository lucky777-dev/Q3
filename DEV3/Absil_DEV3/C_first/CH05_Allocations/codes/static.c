#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//global variable -> static class
const char * policy = "azertyuiopqsdfghjklmwxcvbn0123456789!?.";
//unsigned l = strlen(policy); //can't do

unsigned policy_length()
{
    static unsigned length = 0; //local static variable
    static bool computed = false; //did I already compute length ?
    
    if(! computed)
    {
        length = strlen(policy);
        computed = true;
    }
    
    return length;
}

int main()
{
    int l1 = policy_length(); //O(n)
    int l2 = policy_length(); //O(1)
    int l3 = policy_length(); //O(1)
}
