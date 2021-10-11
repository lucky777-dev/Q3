#include <iostream>

using namespace std;

struct A
{
	int i;	
	A(int i) : i(i) {}
};

struct B
{
	A a;
	//B(A a) : a(a) {};//ok
	
	/*
	B(A a)//ko
	{
		this-> a = a;
	}
	*/
};

int main()
{	
	A a(2);
	B b(a);
}
