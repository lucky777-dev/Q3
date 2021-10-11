#include <iostream>
#include <iomanip>

using namespace std;

int plusOne(void* pv)
{
	int * pi = static_cast<int*>(pv);
	cout << pi << endl;
	(*pi)++; //ask why () are important
	return *pi;
}

struct B {}; //base class
struct D : B {}; //D inherits from B

int main()
{
	int i = 2;
	cout << &i << endl;
	cout << plusOne(&i) << endl;
	cout << i << endl;

    cout << endl;
    
	//<code risqué>
	double f = 27;
	cout << &f << endl;
    cout << scientific << setprecision(30) << f << endl;
	cout << scientific << setprecision(30) << plusOne(&f) << endl;
	cout << scientific << setprecision(30) << f << endl;
	//</code risqué>

    cout << endl;
    
	//int* pti = &f;
	int j = 2;
	double f2 = static_cast<double>(j);
	cout << f2 << endl;

    cout << endl;
    
	D d;
	B& br = d; // upcast via implicit conversion
   	D& another_d = static_cast<D&>(br); // manual downcast

    cout << endl;
    
	D a[10];
	B* dp = static_cast<B*>(a);//array to pointer + upcast
}
