#include <iostream>

using namespace std;

class A
{
    int i;
    
     public:
            A() : i(3) {}
    
            void f() const {}
            void g() {}
};

int main()
{
    int i = 2;
    const int ci = i;
    
    A a;
    const A ca;
    
    i++; //ok
    //ci++; //ko
    
    a.f(); //ok
    a.g(); //ok
    ca.f(); //ok
    //ca.g(); //ko
}
