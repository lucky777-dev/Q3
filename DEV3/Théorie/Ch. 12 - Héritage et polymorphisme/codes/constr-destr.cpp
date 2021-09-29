#include <iostream>

using namespace std;

struct A
{
	A()
	{
		cout << "+A() "<< this << endl;
	}

	A(int a)
	{
		cout << "+A(int) "<< this << endl;
	}

	~A()
	{
		cout << "-A() "<< this << endl;
	}		
};

struct B : A
{
	B()
	{
		cout << "+B() "<< this  << endl;
	}

	B(int a, int b) : A(a)
	{
		cout << "+B(int,int) "<< this  << endl;
	}
			
	~B()
	{
		cout << "-B() "<< this  << endl;
	}
};

int main()
{
	A a; cout << endl;
	A aa(2); cout << endl;
	B b; cout << endl;
	B bb(2,2); cout << endl;
}
