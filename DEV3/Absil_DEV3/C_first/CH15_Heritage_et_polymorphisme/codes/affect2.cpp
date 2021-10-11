#include <iostream>

using namespace std;

class point
{
	protected:
		int x, y;
	
	public:
		point(int a = 0, int b = 0) : x(a), y(b) {}		

		point & operator =(const point& p)
		{
			if(this != &p)
			{
				x = p.x;
				y = p.y;
				cout << "= point" << endl;
			}
			return *this;
		}	

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

		
		pointcol & operator =(const pointcol& p)
		{
			if(this != &p)
			{					
				point & p1 = *this;//we want the same types without truncating
				const point& p2 = p;//we want the same types without truncating, const allows =
				p1 = p2;//affectation in point

				r = p.r; //writing affectation in pointcol
				g = p.g;
				b = p.b;
				cout << "= pointcol" << endl;
			}
			return *this;
		}

		friend ostream& operator << (ostream& out, const pointcol& p)
		{
			out << "( " << p.x << " , " << p.y << " ) - color " << p.r << " " << p.g << " " << p.b;
			return out;
		}
};

int main()
{
	pointcol p1(1,2,255, 128, 128);
	pointcol p2(4,5,255, 128, 128);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << endl;

	p2 = p1;
	cout << p1 << endl;
	cout << p2 << endl;	

	pointcol * pt1 = new pointcol(1,2,255,128,128);
	pointcol * pt2 = new pointcol(4,5,255,128,128);

	delete pt1;

	pt1 = pt2;	
	cout << *pt1 << endl;
	cout << *pt2 << endl;

	delete pt1;
}
