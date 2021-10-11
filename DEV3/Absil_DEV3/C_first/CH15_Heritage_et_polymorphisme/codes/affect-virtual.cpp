#include <iostream>

using namespace std;

class A
{
	public:
		virtual A & operator = (const A&)
		{
			cout << "=A" << endl;
		}
};

class B : public A
{
	public:
		virtual B & operator = (const B&) //override //ko
		{
			cout << "=B" << endl;
		}
};

int main()
{
	A * a1 = new A; A * a2 = new A;
	B * b1 = new B; B * b2 = new B;

	*b1 = *b2;
	*a1 = *b1;//normal -> affect A
	*a1 = *b2;
}
