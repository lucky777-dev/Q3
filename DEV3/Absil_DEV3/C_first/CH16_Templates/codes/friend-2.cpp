#include <iostream>

using namespace std;

template<class T> class A {}; // primary
template<class T> class A<T*> {}; // partial
template<> class A<int> {}; // full

class X 
{
    template<class T> friend class A<T*>; // error!
    friend class A<int>; // OK
};

template<class T> void f(int);
template<> void f<int>(int);
 
class Y 
{
    friend void f<int>(int x = 1); // error: default args not allowed
};

int main()
{

}
