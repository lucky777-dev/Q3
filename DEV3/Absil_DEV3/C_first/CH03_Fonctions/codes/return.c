#include <stdio.h>

int f()
{
    int i = 42;
    return i;
}

int* g()
{
    int i = 42;
    int * pti = &i;
    return pti;
}

void h(int * pt)
{
    int i = 42;
    pt = &i;
}

void hh(int * pt)
{
    int i = 42;
    *pt = i;
}

int main()
{
    printf("%d\n", f());
    //printf("%d\n", *g()); //undefined behaviour
    
    //int * pt = NULL;
    //h(pt);    
    //printf("%d\n", *pt);
    
    //int b;
    //h(&b);    
    //printf("%d\n", b);
    
    int c;
    hh(&c);
    printf("%d\n", c);
}
