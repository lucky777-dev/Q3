#include <iostream>
#include <cstddef>

using namespace std;

int brol = 2;

class point
{
	static int n;
	static int nd;

	int x, y;

	public:
		point(int abs=0, int ord=0) : x(abs), y(ord)
		{
			n++;
			cout << "(+) Number of points : " << n << " - " << abs << " , " << ord << endl;
		}

		~point()
		{
			n--;
			cout << "(-) Number of points : " << n << " - " << x << " , " << y << endl;
		}

		void * operator new(size_t size)
		{
			nd++;
			cout << "(new) Number of dynamic points : " << nd << endl;
			return ::new char[size];
		}

		void operator delete(void * pt)
		{
			nd--;
			cout << "(del) Number of dynamic points : " << nd << endl;
		}
};

int point::n = 0;
int point::nd = 0;

int main()
{
	point * pt1, * pt2;//pas d'appel à new
	point a(3,5);
	
	pt1 = new point(1,3);
	point b;
	pt2 = new point(2,0);
	delete pt1;
	pt1 = new point();
	delete pt1;
	point c(2);
	delete pt2;
}
