#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

const long double PI = atan(1) * 4;

int main()
{
	 cout << left << setw(16)
	      << "default pi" << " : " << PI << endl
	      << left << setw(16) 
	      << "10-digits pi" << " : " << setprecision(10) << PI << endl
	      << left << setw(16)
              << "max-digits pi" << " : " << setprecision(numeric_limits<long double>::digits10 + 1)
              << PI << endl;

	cout << endl;
	
	int n = 42;
	cout << "42 - base 8  : "<< oct << n << endl;
	cout << "42 - base 10 : "<< dec << n << endl;
	cout << "42 - base 16 : "<< hex << n << endl;
}
