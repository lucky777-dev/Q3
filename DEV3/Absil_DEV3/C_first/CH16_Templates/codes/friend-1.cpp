#include <iostream>

using namespace std;

template<class T> class B;
template<class T> int add(T t);

class A 
{
	int i;

	public:	
		A(int i) : i(i) {}

	    template<class T>
    	friend class B; // every B<T> is a friend of A
 
    	template<class T>
    	friend int add(T t); // every f<T> is a friend of A
};

template<class T>
struct B
{
	int i;		
	T t;
	B(const A& a, T t) : i(a.i), t(t) {}
};

template<class T>
int add(T t)
{
	static A a(1);
	a = A(a.i + t);
	return a.i;
}

int main()
{
	A a(3); B<int> b(a,2);
	cout << b.i << endl;

	for(int i = 0; i < 5; i++)
		cout << add(1) << " ";
	cout << endl;
}
