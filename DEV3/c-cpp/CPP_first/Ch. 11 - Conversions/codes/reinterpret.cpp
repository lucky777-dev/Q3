#include <iostream>

using namespace std;

struct A {  char a, b, c, d; };

int main()
{
    int i = 7;

    char* p2 = reinterpret_cast<char*>(&i);
    if(p2[0] == '\x7')
        cout << "This system is little-endian" << endl;
    else
        cout << "This system is big-endian" << endl;

    i = 1094861636; //0x41424344
    A &p = reinterpret_cast<A&>(i); //if little endian : D C B A

    cout << p.a << " " << p.b << " " << p.c << " " << p.d << endl;
}
