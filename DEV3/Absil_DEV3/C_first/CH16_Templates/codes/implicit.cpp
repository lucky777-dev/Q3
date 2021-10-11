#include <iostream>	

using namespace std;
//source : cppreference

template<class T>
void f(T s)
{
    cout << s << endl;
}
 
int main()
{
    f<double>(1); // instantiates and calls f<double>(double)
    f<>('a'); // instantiates and calls f<char>(char)	
    f(7); // instantiates and calls f<int>(int)
    void (*ptr)(std::string) = f; // instantiates f<string>(string)
}
