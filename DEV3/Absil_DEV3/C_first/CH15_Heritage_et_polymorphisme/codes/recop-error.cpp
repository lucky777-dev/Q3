#include <iostream>

using namespace std;

class point
{
	protected:
		int x, y;
	
	public:
		point(int a = 0, int b = 0) : x(a), y(b) {} //try to remove cstr-def

		friend ostream& operator << (ostream& out, const point& p)
		{
			out << "( " << p.x << " , " << p.y << " )";
			return out;
		}
};

class pointcol : public point
{
	short r, g, b;
	
	public:
		pointcol(int x = 0, int y = 0, int r = 0, int g = 0, int b = 0) : point(x,y), r(r), g(g), b(b) {}		

		pointcol(const pointcol &p) : r(p.r), g(p.g), b(p.g)
		{
			cout << "+r pointcol" << endl;
		}	

		friend ostream& operator << (ostream& out, const pointcol& p)
		{
			out << "( " << p.x << " , " << p.y << " ) - color " << p.r << " " << p.g << " " << p.b;
			return out;
		}
};

void f(pointcol p)
{
	cout << "f " << p << endl;
}

int main()
{
	pointcol a(1,2,255,128,128);
	f(a);
}
