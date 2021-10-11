#include <iostream>
#include <cmath>

using namespace std;

class ErrNbr;

class Fraction
{
	unsigned num, denom;
	bool positive;

	public:
		Fraction(int num, int denom) : num(abs(num)), denom(abs(denom)), positive((num > 0 && denom > 0) || (num < 0 && denom < 0))
		{}

		operator ErrNbr();
};

class ErrNbr
{
	double f, error;	

	public:
		ErrNbr(double f, double error = 0) : f(f), error(error) {}
	
		friend Fraction::operator ErrNbr();
};

Fraction::operator ErrNbr()
{
	return positive ? ErrNbr((num + 0.) / denom) : ErrNbr(-((num + 0.) / denom));
}

int main()
{
	Fraction f(1,2);
	ErrNbr e = f;
}
