#include <iostream>

using namespace std;

int k = 2;

void f(int i = 3)
{
    cout << i << endl;   
}

//void g(int n, int m = n * 2) {}

void h(int n, int m = k * 2, int p = 3)
{
	cout << n << " " << m << p << endl;
}

int main()
{	
    f(2);
    f();
	//g(2);
	h(2);
}