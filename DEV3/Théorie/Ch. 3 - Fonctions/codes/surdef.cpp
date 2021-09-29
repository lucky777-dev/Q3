#include <iostream>

using namespace std;

int f(int i)
{
	cout << "Integer " << i << endl; 
	return 0;
}

//double f(int i) {} //return type matters not

//int f(const int i) {} //cv-qualifier lost

int f(double d)
{
	cout << "Double " << d << endl;
	return 0;
}

int f(int i, int j)
{
	cout << "Integers " << i << " et " << j << endl;
}

int main()
{
	int k = 1;
	f(k);
	double d = 2.1;
	f(d);
	f(k,d);
}
