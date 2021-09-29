#include <iostream>

using namespace std;

class point
{
	protected:
		int x, y;
	
	public:
		point(int a = 0, int b = 0) : x(a), y(b) {}

		void print()
		{
			cout << "( " << x << " , " << y << " )" <<endl;
		}
};

class pointcol : public point
{
	short r, g, b;
	
	public:
		pointcol(int x = 0, int y = 0, int r = 255, int g = 255, int b = 255) : point(x,y), r(r), g(g), b(g) {}

		void print()
		{
			cout << "( " << x << " , " << y << " ) - color : "
			     << r << " , " << g << " , " << b << endl;
		}
};

int main()
{
	point p(3,5);	
	pointcol pc (8,6,255,128,128);	

	p.print();
	pc.print();

	p = pc; //truncated
	p.print(); //no polymorphism

	point * ptp = &p;
	pointcol * ptpc = &pc;
	ptp = ptpc; //no polymorphism
	ptp -> print();	
    
    point & rp = p;
    pointcol & rpc = pc;
    rp = rpc;
    rp.print(); //no polymotphism
}
