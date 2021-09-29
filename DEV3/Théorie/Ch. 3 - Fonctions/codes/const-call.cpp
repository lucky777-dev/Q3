#include <iostream>

using namespace std;

struct A
{
    void brol() const { cout << "A::brol() const" << endl; }
    void brol() { cout << "A::brol()" << endl; }

    void brol2(A) { cout << "A::brol2(A)" << endl; }
    //void brol2(const A) { cout << "A::brol2(const A)" << endl; } //ERROR : cv-qualifier lost
};

int main()
{
    A a = A();//creates an A (rvalue to lvalue conv)
    const A ca = A();//creates an A (rvalue to lvalue conv)

    a.brol();  //brol
    ca.brol(); //brol const

    a.brol2(a);
    a.brol2(ca);
}
