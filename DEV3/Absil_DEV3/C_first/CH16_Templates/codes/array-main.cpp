#include "array-spec.hpp"
//#include "array.hpp"
#include <iostream>

using namespace std;

template<class T, int N>
void f(Array<T,N> a) {}

int main()
{
	Array<int,5> a1;	
	cout << a1 << endl << endl;    
    
	Array<int,6> a2 = {1,2,3,4,5,6};
	cout << a2 << endl << endl;
    
    Array<int*,3> a_add;
    int n[3];
    for(unsigned i = 0; i < 3; i++)
    {
        n[i] = i + 1;
        a_add[i] = &(n[i]);
    }
    cout << a_add << endl;
    //Array<int*,3> tmp = {&(n[0]), &(n[1]), &(n[2])};
    //cout << tmp << endl;
    for(unsigned i = 0; i < 3; i++)
        cout << *(a_add[i]) << " ";
    cout << endl << endl;    
    
    Array<Array<int,2>,3> a2d = {{1,2},{3,4},{5,6}};
    cout << a2d << endl;    
    for(unsigned i = 0; i < 3; i++)
    {
        for(unsigned j = 0; j < 2; j++)
            cout << a2d[i][j] << " ";
        cout << endl;
    }
    
    //f(Array<int,5>()); //just to check move semantics            
}
