#include <iostream>

using namespace std;

void f(int & i)
{
	cout << "Ref " << i << endl;
}

void f(const int & i)
{
	cout << "Ref cst " << i << endl;
}

int main()
{
	int n = 3;
	const int m = 5;
	f(n);
	f(3);
	f(int{4});
	f(4 * n);
	f(4 * m);
	f(m);
}
