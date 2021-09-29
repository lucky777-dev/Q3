#include <iostream>
#include <string>

using namespace std;

string f1()
{
    string s = "Hello World!";
    return s; //returns a copy of s
}

string& f2()
{
    string s = "Hello World!";
    string & rs = s;
    return rs;
}

string* f3()
{
    string s = "Hello World!";
    string * rs = &s;
    return rs;
}

int main()
{
    cout << f1() << endl;
    cout << f2() << endl; //undefined behaviour
    cout << *(f3()) << endl; //undefined behaviour
}
