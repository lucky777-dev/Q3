#include <iostream>
#include <cmath>

using namespace std;

class point
{
	double x, y;

	public:
		point(int x = 0, int y = 0) : x(x), y(y) {}

		double getX() const
		{
			return x;
		}

		double getY() const
		{
			return y;
		}		

		double dist(point p) const
		{
			return sqrt((x - p.x)*(x - p.x)+(y - p.y)*(y - p.y));
		} 	
};

int main()
{
	point p1(1,1);
	//cout << p1.x << " " << p1.y << endl; //ko
	cout << p1.getX() << " " << p1.getY() << endl;
	point p2(2,2);
	cout << p2.getX() << " " << p2.getY() << endl;
	cout << "dist = " << p1.dist(p2) << endl;
}
