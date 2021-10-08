#include <iostream>

using namespace std;

class point
{
	protected:
		int x, y;
	
	public:
		point(int a = 0, int b = 0) : x(a), y(b) {}

		virtual void print()
		{
			cout << "( " << x << " , " << y << " )" << endl;
		}
};

class pointcol : public point
{
	short r, g, b;
	
	public:
		pointcol(int x = 0, int y = 0, int r = 255, int g = 255, int b = 255) : point(x,y), r(r), g(g), b(b) {}

		void print()
		{
			cout << "( " << x << " , " << y << " )" 
			     << " -- color " << r << " " << g << " " << b << endl;
		}
};

int main()
{
	point p(3,5);
	pointcol pc (3,5,128);
	point * ptp = &p;
	pointcol * ptpc = &pc;

	ptp -> print();
	ptpc -> print();
	cout << endl;

	ptp = ptpc;
	ptp -> print();
	ptpc -> print();//calls pointcol::print
}
