#include <iostream>
#include <cmath>

using namespace std;

constexpr double PI = atan(1) * 4;//ok : atan is constexpr

constexpr int factorial(unsigned n)//C++11 : recursion
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

constexpr long long int test(long long int n)//c++14
{
	int i = n;
	while(i >= 0)
		i--;
	return i;
}

template<int n>
struct constN //compile time outputs
{
    constN() { cout << n << endl; }
};

int main()
{	
	cout << "10! = ";
	constN<factorial(10)> out1;

	cout << "PI = " << PI << endl;

	cout << "test(9999999)=";
//	constN<test(9999999)> out3;
	cout << test(9999999) << endl;
}
