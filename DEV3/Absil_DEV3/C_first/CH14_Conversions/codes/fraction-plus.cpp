#include <iostream>

using namespace std;

class fraction
{
	unsigned num, denom;
	bool positive;

	public:
		fraction(int num = 0, int denom = 1) : num(abs(num)), denom(abs(denom)), positive((num > 0 && denom > 0) || (num < 0 && denom < 0))
		{}		

		operator double() const
		{
			return positive ? (double)num / denom : -((double)num / denom);
		}		
		
		friend std::ostream& operator<<(std::ostream& out, const fraction& p);
};

ostream& operator<<(ostream &out, const fraction &p)
{
    if(! p.positive)
        out << "-";

    if(p.num == 0)
        out << "0";
    else if(p.denom == 1)
        out << p.num;
    else
        out << p.num << " / " << p.denom;

    return out;
}

int main()
{
	fraction f = (-1,2);
	cout << f << endl;

	f = 12;
	cout << f << endl;
}
