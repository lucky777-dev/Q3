#include <iostream>
#include <functional>

using namespace std;

int fwd(function<int (int, int)> f, int a, int b)
{
	return f(a, b);
}

int add(int a, int b)
{
	return a + b;
}

struct A
{
	int i;
	A(int i) : i(i) {}
	int add(int j) { return i += j; }
};

int fwd(function<int (A&, int)> member, A& a, int j)
{
    return member(a, j);
}

int main()
{
	cout << fwd(add, 2, 3) << endl;
	
	A a(2);
	cout << fwd(&A::add, a, 3) << endl;
}
