#include <stdio.h>

struct A 
{
    int i;
};
typedef struct A A; //comment

union B {};
typedef union B B; //comment

//void print(struct A a)
void print(A a)
{
    printf("A[%d]\n", a.i);
}

//void print_addr1(struct A* a)
void print_addr1(A * a)
{
    printf("A with attribute %d located at %p\n", a->i, a);
}

//void print_addr2(union B* b)
void print_addr2(B * b)
{
    printf("%p\n", b);
}

int main()
{
    A a; B b;
    a.i = 2;
    //struct A a; union B b;
    print_addr1(&a);
    print_addr2(&b);
}