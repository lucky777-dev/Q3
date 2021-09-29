#include <iostream>

using namespace std;

class B;

class A
{
	int _i;
	
	public:
		A(int i) : _i(i) {}
		int i() const { return _i; }

		friend class B;
};

class B
{
	A a;
	int _j;
	
	public:
		B(A a, int j) : a(a), _j(j) {}

		int brol() const { return a._i * _j; }	
};

int main()
{
	A a(4);
	B b(a, 3);
	cout << b.brol() << endl;
}
