#include <iostream>

using namespace std;

template<typename T> // primary
struct A
{
    struct C {};
    void f();
    struct D 
	{
        void g();
    };
};
 
template<> // full
struct A<int>
{
    struct C {};
    int f(); //!= signature
    struct D 
	{
        void g();
    };
};
 
class B // non-template
{
    template<class T>
    friend struct A<T>::C; // A<int>::C is a friend, as well as all A<T>::C
 
    template<class T>
    friend void A<T>::f(); // A<int>::f() is not a friend, because the
                           // signatures do not match, but A<char>::f() is
 
    template<class T>
    friend void A<T>::D::g(); // A<int>::D::g() is not a friend: it is not a member
                              // of A, and A<int>::D is not a specialization of A<T>::D
};

int main()
{

}
