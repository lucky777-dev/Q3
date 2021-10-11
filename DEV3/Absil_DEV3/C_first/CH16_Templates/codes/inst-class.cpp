#include <iostream>

using namespace std;

namespace N 
{
  template<class T> class Y { void mf() { } }; // template definition
}
// template class Y<int>; // error: class template Y not visible in the global namespace
using N::Y;
// template class Y<int>; // error: explicit instantiation outside 
                          // of the namespace of the template
template class N::Y<char*>;      // OK: explicit instantiation
template void N::Y<double>::mf(); // OK: explicit instantiation

template<class T> struct Z {
    void f() {}
    void g(); // never defined
}; // template definition
template struct Z<double>; // explicit instantiation of Z<double>

int main()
{
	Z<int> a; // implicit instantiation of Z<int>
	Z<char>* p; // nothing is instantiated here
	p->f(); // implicit instantiation of Z<char> and Z<char>::f() occurs here.
	// Z<char>::g() is never needed and never instantiated: it does not have to be defined
}
