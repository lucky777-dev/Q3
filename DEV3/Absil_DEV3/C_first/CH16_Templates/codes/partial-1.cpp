#include <iostream>

using namespace std;

template<class T> struct A
{
	T t;
	A(T t) : t(t) {}
	
	void print() { cout << t << endl; }
};

template<class T> struct A<T*>
{
	T* t;
	A(T* t) : t(t) {}
	
	void print() { cout << *t << endl; }
};

int main()
{
	int i = 2;
	A<int> a1(i); a1.print();
	A<int*> a2(&i); a2.print();
}
