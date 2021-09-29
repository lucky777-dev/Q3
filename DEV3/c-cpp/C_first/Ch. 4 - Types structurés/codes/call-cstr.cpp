struct A
{
    int x;
    A(int x = 1): x(x) {} // user-defined default constructor
};
 
struct B : A //B inherits A
{
    // B::B() implicitly-defined, calls A::A()
};
 
struct C
{
    A a;
    // C::C() implicitly-defined, calls A::A()
};
 
struct D : A //D inherits A
{
    D(int y) : A(y) {}
    // D::D() not declared    
};
 
struct E : A
{
    A a;
    E(int y) : A(y) {}
    E() = default; // explicitly defaulted, calls A::A()
};
 
struct F
{
    int& ref;    
    // F::F() is implicitly defined as deleted
};
 
struct G
{
    const int c;   
    // G::G() is implicitly defined as deleted
};

struct H
{
    D d;
    // H::H() is implicitly defined as deleted
};


int main()
{
    A a;
    B b;
    C c;
//  D d; // compile error
    E e;
//  F f; // compile error
//  G g; // compile error
//  H h; // compile error
}