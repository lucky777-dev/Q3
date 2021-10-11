#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
	public:
	    shared_ptr<B> ptB;
};

class B
{
    public:
	    shared_ptr<A> ptA;
};

int main()
{
	shared_ptr<A> a(new A);
	shared_ptr<B> b(new B);
	cout << a.use_count() << ", " << b.use_count() << endl;
	a->ptB = b;
	cout << a.use_count() << ", " << b.use_count() << endl;
	b->ptA = a;
	cout << a.use_count() << ", " << b.use_count() << endl;
	a.reset();
	b.reset();
	cout << a.use_count() << ", " << b.use_count() << endl;
}
