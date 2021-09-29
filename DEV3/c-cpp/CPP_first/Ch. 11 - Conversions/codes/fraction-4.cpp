#include <iostream>
#include <cmath>

using namespace std;

class fraction
{
	unsigned num, denom;
	bool positive;

	public:
		fraction(int num = 0, int denom = 1) : num(abs(num)), denom(abs(denom)), positive((num > 0 && denom > 0) || (num < 0 && denom < 0))
		{}

        friend fraction operator *(const fraction& f1, const fraction& f2);
};

fraction operator *(const fraction& f1, const fraction& f2)
{
    return fraction(f1.num * f2.num, f1.denom * f2.denom);   
}

int main()
{
	fraction f {1, 2};
    
    f * 2;
    2 * f;
    f * 2.1;
    2.1 * f;
}
