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

		fraction& operator =(const fraction& f)
		{
			cout << "Affectation fraction " << f.num << " " << f.denom << " " << f.positive << endl;

			num = f.num; 
			denom = f.denom;
			positive = f.positive;

			return *this;
		}

		fraction& operator =(const int n)
		{
			cout << "Affectation int " << n << endl;

			num = abs(n);
			denom = 0;
			positive = n > 0;

			return *this;
		}
	
};

int main()
{
	fraction fr(1,2);
	fr = 12;
}
