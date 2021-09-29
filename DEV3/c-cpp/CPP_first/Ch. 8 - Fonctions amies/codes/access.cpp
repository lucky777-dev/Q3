#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class point
{	
	double _x, _y;//ask why I wrote _x

	public :		

		point(double abs=0, double ord=0) : _x(abs), _y(ord) {}

		double distance(point p)
		{
			return sqrt((_x - p._x) * (_x - p._x) 
				+ (_y - p._y) * (_y - p._y));
		}

		string toString()
		{
			stringstream str;
			str << "( " << _x << " , " << _y << " )";		
			return str.str();
		}

		inline void set(int abs, int ord)
		{
			_x = abs;
			_y = ord;
		}

		inline double x() const
		{
			return _x;
		}

		inline double y() const
		{
			return _y;
		}
};

class circle
{
	point _center;
	double _rad;

	public :
		circle(point p, double rad) : _center(p), _rad(rad) {}		

		void translate(double x, double y)
		{
			_center.set(_center.x() + x, _center.y() + y);
		}

		string toString()
		{			
			stringstream str;
			str << "Circle of center " << _center.toString() << " and of radius " << _rad;
			return str.str();
		}
};

int main()
{
	point p (1,1);
	circle c (p, 2);

	cout << p.toString() << "\n";
	cout << c.toString() << "\n";

	c.translate(1,-1);

	cout << p.toString() << "\n";
	cout << c.toString() << "\n";	
}
