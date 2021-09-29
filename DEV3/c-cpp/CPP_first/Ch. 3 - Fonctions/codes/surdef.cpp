#include <iostream>

using namespace std;

int f(int i) //try to comment that
{
	cout << "Integer " << i << endl; 
	return 0;
}

/*
int f(long int i)
{
	cout << "Long Integer " << i << endl; 
	return 0;
}
*/

//double f(int i) {} //return type matters not

//int f(const int i) {} //cv-qualifier lost

int f(double d) //try to comment that
{
	cout << "Double " << d << endl;
	return 0;
}

int f(int i, int j)
{
	cout << "Integers " << i << " and " << j << endl;
}

int main()
{
	int k = 1;
	f(k);
	double d = 2.1;
	f(d);
	f(k,d);
}






