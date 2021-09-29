struct A
{
    int x;
    A(int x = 1): x(x) {} // user-defined default constructor
};
 
struct B : A
{
    // B::B() implicitly-defined, calls A::A()
};
 
struct C
{
    A a;
    // C::C() implicitly-defined, calls A::A()
};
 
struct D: A
{
    D(int y): A(y) {}
    // D::D() not declared
};
 
struct E: A
{
    E(int y): A(y) {}
    E() = default; // explicitly defaulted, calls A::A()
};
 
struct F
{
    int& ref; 
    const int c;
    // F::F() is implicitly defined as deleted
};
 
int main()
{
    A a;
    B b;
    C c;
//  D d; // compile error
    E e;
//  F f; // compile error
}