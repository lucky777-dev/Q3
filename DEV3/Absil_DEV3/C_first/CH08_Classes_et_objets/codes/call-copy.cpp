#include <iostream>

using namespace std;

struct A
{
    int n;
    A(int n = 1) : n(n) { cout << "+A" << endl; }
    A(const A& a) : n(a.n) { cout << "cA" << endl; } 
};

struct B
{
    B() { cout << "+B" << endl; }
    B(const B&) = delete;
};
 
void f1(A a) {}
void f2(A& a) {}

A f3()
{
    A a; 
    return a;
}

void f4(B b) {}
void f5(B& b) {}

/*
B f6()
{
    B b;
    return b;
}
*/

int main()
{
    A a1(7);
    A a2(a1);  //explicit copy
    A a3 = a2; //no copy
    
    f1(a1); //copy
    f2(a1);
    A a4 = f3();
    
    B b;    
    //f4(b);
    f5(b);
    
    //B b2 = f6();
}
