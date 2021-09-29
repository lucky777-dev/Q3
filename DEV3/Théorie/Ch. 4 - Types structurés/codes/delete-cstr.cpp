#include <iostream>

using namespace std;

struct A { int i; };
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
    
    //AD ad;
    AD ad{};
    AD ad2{42};
}
