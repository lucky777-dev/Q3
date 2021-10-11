#include <iostream>

using namespace std;

class fraction
{
	unsigned num, denom;
	bool positive;

	public:
		fraction(int num = 0, int denom = 1) : num(abs(num)), denom(abs(denom)), positive((num > 0 && denom > 0) || (num < 0 && denom < 0))
		{
            cout << "+" << num << "/" << denom << endl;
		}				

		operator int() const
		{
			cout << "Call cast " << num << " " << denom << " " << positive << endl;
			return positive ? num / denom : -(num / denom);
		}
    
        friend fraction operator * (fraction,fraction);            
};

fraction operator *(fraction f1, fraction f2)
{
    return fraction(f1.num * f2.num, f1.denom * f2.denom);   
}

int main()
{
    fraction f1 {1,2};
    
    int i = (f1 * 2.1);
}