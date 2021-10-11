#include <iostream>

using namespace std;

class point
{
	double _x, _y;

	public:
		point(double x = 0, double y = 0) : _x(x), _y(y) {}

		inline double x() const { return _x; }
		inline double y() const { return _y; }

		friend ostream& operator << (ostream& out, const point& p);
};

ostream& operator << (ostream& out, const point& p)
{
	out << "(" << p._x << " , " << p._y << ")";
	return out;
}

int main()
{
	point p;
	cout << p << endl; 
	p = point(2,3);
	cout << p << endl;
}
