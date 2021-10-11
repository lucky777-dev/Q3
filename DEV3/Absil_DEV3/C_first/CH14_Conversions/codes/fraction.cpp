#include <iostream>
#include <cmath>

using namespace std;

class fraction
{
	unsigned num, denom;
	bool positive;

	public:
		fraction(int num, int denom) : num(abs(num)), denom(abs(denom)), positive((num > 0 && denom > 0) || (num < 0 && denom < 0))
		{
			cout << "Call cstr " << num << " " << denom << endl;
		}		

		fraction(const fraction& f) : num(f.num), denom(f.denom), positive(f.positive)
		{
			cout << "Call copy cstr" << endl;
		}

		operator int() const
		{
			cout << "Call cast " << num << " " << denom << " " << positive << endl;
			return positive ? num / denom : -(num / denom);
		}
};

void f1(int n)
{
	cout << "Call f1(int) " << n << endl;
}

void f2(double x)
{
	cout << "Call f2(double) " << x << endl;
}

int main()
{
	fraction a(5,-2), b(2,5);
	int n1, n2;
	double x1, x2;
	cout << endl;

	n1 = static_cast<int>(a);
	cout << "n1 = " << n1 << endl;
	n2 = b;
	cout << "n2 = " << n2 << endl << endl;

	f1(a); f2(a);
	cout << endl;

	n1 = a + 3;
	cout << "n1 = " << n1 << endl;
	n2 = a + b;
	cout << "n2 = " << n2 << endl << endl;

	x1 = a + 3;
	cout << "x1 = " << x1 << endl;
	x2 = a + b;
	cout << "x2 = " << x2 << endl << endl;
	
	n1 = a + 3.85;	
	cout << "n1 = " << n1 << endl;
	x1 = a + 3.85;
	cout << "x1 = " << x1 << endl;
	x2 = a;
	cout << "x2 = " << x2 << endl << endl;	
}
