#include <iostream>
#include <cmath>

using namespace std;

class point
{
	double x, y;
	bool copie;

	public:
		point(int x, int y)
		{
			this->x = x;
			this->y = y;
			copie = false;
		
			cout << "Construction de " << x << " " << y << endl;
		}

		point(const point& p)
		{
			this-> x = p.x;
			this-> y = p.y;
			copie = true;
		
			cout << "Copie de " << x << " " << y << endl;
		}	

		~point()
		{
			cout << "Destruction de " << x << " " << y;
			if(copie)
				cout << " (copie)";
			cout << endl;
		}

		inline double getX() const
		{
			return x;
		}

		inline double getY() const
		{
			return y;
		}

		inline double dist(point p) const
		{
			return sqrt((x - p.x)*(x - p.x)+(y - p.y)*(y - p.y));
		}
};

void sayHello(point p)//fct indep, try with &, *
{
	cout << "Hello Mr point " << p.getX() << " " << p.getY() << endl;
}

int main()
{
	point p1(0,0);
	point p2(1,1);
	cout << p1.getX() << " " << p1.getY() << endl;
	sayHello(p1);
	cout << p2.getX() << " " << p2.getY() << endl;
	cout << "dist = " << p1.dist(p2) << endl;
	
	point p3(p1);//explicit copy
	p3 = p2;	
}
