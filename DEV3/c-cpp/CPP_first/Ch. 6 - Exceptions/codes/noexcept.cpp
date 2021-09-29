#include <iostream>

using namespace std;

struct A
{
	int f() noexcept { return 1; }
};

struct B : A
{
	int f() { return 2; } //ok, noexcept inherited
};

void f() noexcept;

void f() {} //ko : different exception specifier

int main()
{

}
