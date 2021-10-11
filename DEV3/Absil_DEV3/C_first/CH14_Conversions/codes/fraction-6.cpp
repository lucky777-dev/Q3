#include <iostream>
#include <cmath>

using namespace std;

class Fraction; //talk about why it is switched

class ErrNbr
{
	double f, error;	

	public:
		ErrNbr(double f, double error = 0) : f(f), error(error) {}
		ErrNbr(Fraction f);
};

class Fraction
{
	unsigned num, denom;
	bool positive;

	public:
		Fraction(int num, int denom) : num(abs(num)), denom(abs(denom)), positive((num > 0 && denom > 0) || (num < 0 && denom < 0))
		{}

		friend ErrNbr::ErrNbr(Fraction);
};

ErrNbr::ErrNbr(Fraction f)  : f(f.positive ? (f.num + 0.) / f.denom : -((f.num + 0.) / f.denom)), error(0)
{}

int main()
{
	Fraction f(1,2);
	ErrNbr e = f;
}
