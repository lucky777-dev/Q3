#include <stdio.h>

struct A {};
typedef struct A A; //comment

union B {};
typedef union B B; //comment

//void print_addr1(struct A* a)
void print_addr1(A * a)
{
    printf("%p\n", a);
}

//void print_addr2(union B* b)
void print_addr2(B * b)
{
    printf("%p\n", b);
}

int main()
{
    A a; B b;
    //struct A a; union B b;
    print_addr1(&a);
    print_addr2(&b);
}