#include <iostream>

using namespace std;

void f(int & lref) // l-value arguments will select this function
{
	cout << "l-value reference" << endl;
}

void f(const int & lref) // const l-value arguments will select this function
{
	cout << "l-value reference to const" << endl;
}
 
void f(int && rref) // r-value arguments will select this function
{
	cout << "r-value reference" << endl;
}
 
int main()
{
	int x{ 5 };
	const int y {5};
	int & rx = x;
	const int & ry = ry;
	f(x); // l-value argument calls l-value version of function
	f(y);
	f(rx); // l-value argument calls l-value version of function
	f(ry);
	f(5); // r-value argument calls r-value version of function
}
