#include <iostream>

using namespace std;

struct A
{
    int i;
    
    A(int i = 0) : i(i) { cout << "+" << endl; } //default cstr
    A(const A& a) : i(a.i) { cout << "c" << endl; } //copy cstr
    A(A&& a) : i(std::move(a.i)) {cout << "m" << endl; } //move cstr
    A& operator=(const A& a)
    {
        cout << "=c" << endl;
        if(this != &a)
            i = a.i;
        return *this;
    }
    
    A& operator=(A&& a)
    {
        cout << "=m" << endl;
        i = std::move(a.i);
        return *this;
    } 
};

//void f(A a) { cout << "by value" << endl; }  //1
void f(A& a) { cout << "by ref" << endl; } //2
void f(const A& a) { cout << "by const ref" << endl; } //2
void f(A&& a) { cout << "by rvalue ref" << endl; } //2

A g() { return A(); }

int main()
{
    A a1(1);
    f(a1);
    
    cout << endl;
    
    const A a2(2);
    f(a2);
    
    cout << endl;
    
    f(A(3));
    
    cout << endl;
    
    A a = g();
    
    cout << endl;
    
    a = g();
}
