#include <iostream>

using namespace std;

struct Array
{
    int i;
    int * arr;
    
    Array(int i) : i(i)
    {
        arr = new int[i];
    }    
}; //missing destructor... and other things

int main()
{
    Array a(2); //a automatic
                //i automatic
                //arr automatic
                //*arr dynamic
    
    cout << "Automatic" << endl;
    cout << &a << endl;
    cout << &(a.i) << endl;
    cout << &(a.arr) << endl;
    cout << &(*(a.arr)) << endl << endl;        
    
    static Array b(2); //b static
                       //i static
                       //arr static
                       //*arr dynamic
    
    cout << "Static" << endl;
    cout << &b << endl;
    cout << &(b.i) << endl;
    cout << &(b.arr) << endl;
    cout << &(*(b.arr)) << endl << endl;    
    
    Array * c = new Array(2); //c dynamic
                              //i dynamic
                              //tab dynamic
                              //*tab dynamic
    cout << "Dynamic" << endl;
    cout << c << endl;
    cout << &(c->i) << endl;
    cout << &(c->arr) << endl;
    cout << &(*(c->arr)) << endl << endl;
}
