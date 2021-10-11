#include <iostream>

using namespace std;
//source : cppreference

template<class T>
void f(T s)
{
    cout << s << endl;
}
 
template void f<double>(double); // instantiates f<double>(double)
template void f<>(char); // instantiates f<char>(char), template argument deduced
template void f(int); // instantiates f<int>(int), template argument deduced

//not a use of default arguments
char* p = 0;
template<class T> T g(T x = &p) { return x; }
template int g<int>(int);   // OK even though &p isn’t an int.

int main()
{

}
