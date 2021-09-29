#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class fraction
{
	unsigned num, denom;
	bool positive;

	public:
		fraction(int num = 0, int denom = 1);
		fraction(unsigned num, unsigned denom, bool positive);

		fraction operator *(fraction f) const;
		//friend fraction operator *(fraction f1, fraction f2);
		
		string toString()
		{
			stringstream str;
			if(! positive)
				str << "-";
			str << num << " / " << denom;
			return str.str();
		}
};

fraction::fraction(int num, int denom) 
	: num(abs(num)), denom(abs(denom)), positive((num >= 0 && denom >= 0) || (num <= 0 && denom <= 0))
{}

fraction::fraction(unsigned num, unsigned denom, bool positive) 
	: num(num), denom(denom), positive(positive)
{}

fraction fraction::operator *(fraction f) const
{
	return fraction(num * f.num, denom * f.denom, 
		(positive && f.positive) || (!positive && !f.positive));
}

/*
fraction operator*(fraction f1, fraction f2)
{
	return fraction(f1.num * f2.num, f1.denom * f2.denom, 
		(f1.positive && f2.positive) || (! f1.positive && !f2.positive));
}
*/

int main()
{
	fraction f1 (2,3,true);// 2/3
	fraction f2 (-4,5); //- 4 / 5
	
	fraction f3 = f1 * f2;
	cout << f3.toString() << endl;

	cout << (f1 * f2 * f3).toString() << endl; //track what happens with prints
}
