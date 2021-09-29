#include <iostream>

using namespace std;

class point
{
	int x, y;
	
	public:
		point(int x = 0, int y = 0) : x(x), y(y) {}
		
		void setLocation(int x, int y)
		{
			this -> x = x;
			this -> y = y;
		}

		friend ostream& operator <<(ostream& out, const point& p)
		{
			out << "( " << p.x << " , " << p.y << " )";
		}	
};

class pointcol : public point
{
	short r, g, b;
	
	public:
		pointcol(int x, int y, short r, short g, short b) : point(x,y), r(r), g(g), b(b) {}
};

class pointcol_pr : private point
{
	short r, g, b;
	
	public:
		pointcol_pr(int x, int y, short r, short g, short b) : point(x,y), r(r), g(g), b(b) {}

		/**
		void setLocation(int x, int y)
		{
			point::setLocation(x, y);
		}
		*/
		using point::setLocation;

		friend ostream& operator <<(ostream& out, const pointcol_pr& p)
		{
			out << (point)p << p.r << " " << p.g << " " << p.b << endl;
		}	
};

int main()
{
	pointcol p(1,2,80,0,0);
	cout << p << endl;

	p.setLocation(3,4);
	cout << p << endl;

	pointcol_pr p2(1,2,80,0,0);
	cout << p2 << endl;

	p2.setLocation(3,4);
	cout << p2 << endl;		
}
