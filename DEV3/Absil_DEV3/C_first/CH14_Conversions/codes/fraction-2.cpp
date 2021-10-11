#include <iostream>
#include <cmath>

using namespace std;

class fraction
{
	unsigned num, denom;
	bool positive;

	public:
		fraction(int num = 0, int denom = 1) : num(abs(num)), denom(abs(denom)), positive((num > 0 && denom > 0) || (num < 0 && denom < 0))
		{
			cout << "Call cstr " << num << " " << denom << endl;
		}		

		fraction(const fraction& f) : num(f.num), denom(f.denom), positive(f.positive)
		{
			cout << "Call copy cstr" << endl;
		}
};

void f(fraction f)
{
	cout << "Call f " << endl;
}

int main()
{
	fraction fr(1,2);
	fr = fraction(3);
	fr = 12;

	f(5);
}
