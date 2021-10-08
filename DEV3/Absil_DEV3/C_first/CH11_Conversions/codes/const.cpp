#include <iostream>

using namespace std;

struct A 
{
    A() : i(3) {}
    void m1(int v) const 
    {
        // this->i = v;                 // compile error: this is a pointer to const
        const_cast<A*>(this)->i = v; // OK as long as the type object isn't const
    }
    int i;
};
 
int main() 
{
    int i = 3;               
    const int& cref_i = i; //const ref
    const_cast<int&>(cref_i) = 4; // OK: modifies i
    cout << "i = " << i << endl;
 
    A a;
    a.m1(4); //if a is const : undefined behaviour
    cout << "A::i = " << a.i << endl;
 
    const int j = 3; // j is declared const
    int* pj = const_cast<int*>(&j);
    *pj = 4;         // undefined behavior!
}
