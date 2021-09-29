#include <iostream>
#include <cstddef>

using namespace std;

class Point
{
	int x, y;

	public:
		Point(int x = 0, int y = 0) : x(x), y(y) {}

		inline int getX() const { return x; }
		inline int getY() const { return y; }

		void setLocation(int x, int y) 
		{
			this->x = x;
			this->y = y;
		}
};

int main()
{
	Point * p = new Point(2,3);
	cout << p->getX() << " " << p->getY() << endl;
	delete p;
	cout << p->getX() << " " << p->getY() << endl;//unpredictable is p is deleted
	
	Point * p2 = nullptr;
	Point * pp2 = nullptr;

	Point p3;//(0,0)

	{
		p2 = new Point(3,4);
		cout << p2->getX() << " " << p2->getY() << endl;
		pp2 = p2;

		p3 = *p2;		
		//delete p2;//uncomment
	}

	cout << p2->getX() << " " << p2->getY() << endl;
	cout << pp2->getX() << " " << pp2->getY() << endl;		
	cout << p3.getX() << " " << p3.getY() << endl;	
}
