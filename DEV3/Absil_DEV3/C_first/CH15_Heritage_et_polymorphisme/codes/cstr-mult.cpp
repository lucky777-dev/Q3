#include <iostream>

using namespace std;

struct A
{
	A() { cout << "+A" << endl; }
	A(const A& a) { cout << "rA" << endl; }
	virtual ~A() { cout << "-A" << endl; }

	virtual int nbr() const { return 1; }
};

struct B
{
	B() { cout << "+B" << endl; }
	B(const B& a) { cout << "rB" << endl; }
	virtual ~B() { cout << "-B" << endl; }

	virtual int nbr() const { return 2; }
};

struct C : A, B
{
	C() { cout << "+C" << endl; }
	C(const C& a) { cout << "rC" << endl; }
	virtual ~C() { cout << "-C" << endl; }

	virtual int nbr() const { return 12; }
};

void f(A a) {}

void fpol(A & a) {}

int main()
{
	C c;
	cout << endl;
	f(c);
	cout << endl;

	C * cc = new C();
	cout << endl;	

	A& a = *cc;
	fpol(a);
	cout << a.nbr() << endl;

	delete cc;
	cout << endl;
}
