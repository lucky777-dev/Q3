#include <iostream>

using namespace std;

class point
{
	int x, y;
	
	public:
		point(int a = 0, int b = 0) : x(a), y(b) {}

		virtual void print()
		{
			cout << "(" << x << " , " << y << ")";			
		}
};

class color
{
	short r, g, b;

	public:
		color(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}

		virtual void print()
		{
			cout << "[" << r << " , " << g << " , " << b << "]";
		}
};

class pointcol : public point, public color
{	
	public:
		pointcol(int x = 0, int y = 0, int r = 0, int g = 0, int b = 0) 
			: point(x,y), color(r,g,b) {}

		void print() override
		{
			cout << "{ ";
			point::print();
			cout << " , ";
			color::print();
			cout << " }";
		}
};

int main()
{
	pointcol p(1,2,100,128,255);
	p.print(); cout << endl;
	p.point::print(); cout << endl;
	p.color::print(); cout << endl;
	

	color & c = p;
	c.print(); cout << endl;

	point& pp = p;
	pp.print(); cout << endl;
}
