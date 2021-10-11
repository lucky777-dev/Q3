#include <iostream>

using namespace std;

struct A 
{
    void f() {}
};
struct B 
{ 
    int i; 
    void g() {}  
};

//wrong
template<class T> bool is_A(T t)
{
    return sizeof(T) == sizeof(A);   
}

template<class T> bool is_B(T t)
{
    return sizeof(T) == sizeof(B);   
}

template<class T>
void brol(T t)
{
    if (is_A<T>(t))
        t.f(); //can't find f if t is B
    else
        t.g(); //can't find g if t is A
}

/*
//Right
template<class T> constexpr bool is_A()
{
    return sizeof(T) == sizeof(A);   
}

template<class T> constexpr bool is_B()
{
    return sizeof(T) == sizeof(B);   
}

template<class T>
void brol(T t)
{
    if constexpr(is_A<T>())
        t.f();
    else
        t.g();
}
*/

int main()
{
    A a;
    B b;
    brol(a);
    brol(b);
}
