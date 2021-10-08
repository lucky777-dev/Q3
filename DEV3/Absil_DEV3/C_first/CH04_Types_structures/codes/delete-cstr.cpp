#include <iostream>

using namespace std;

//implicitelely defined default cstr
struct A 
{ 
    int i; 
};

//explicitelely defined default cstr
struct AB 
{ 
    int i; 
    
    AB(int i = 23)
    {
        this->i = i;
    }
};

//deleted default cstr
struct AD
{
    int i;
    AD() = delete;
};

int main()
{
    A a1;     //i not init
    A a2{};   //i = 0
    A a3{42}; //i = 42
    cout << a1.i << " " << a2.i << " " << a3.i << endl;
    
    AB ab1;     //i = 23
    AB ab2{};   //i = 23
    AB ab3{42}; //i = 42
    cout << ab1.i << " " << ab2.i << " " << ab3.i << endl;
    
    AB abb1();
    AB abb2(17);
    AB abb3{17};
    AB abb4(17.5);
    //AB abb5{17.5}; //ko : no implicit conversion
    
    //AD ad0;
    AD ad1{};
    AD ad2{42};
    cout << ad1.i << " " << ad2.i << endl;   
}
