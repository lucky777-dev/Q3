#include <iostream>
#include "point-decl-impl.h"

using namespace std;

int main()
{
	point p1(1,1);
	cout << p1.getX() << " " << p1.getY() << endl;
	point p2(2,2);
	cout << p2.getX() << " " << p2.getY() << endl;
	cout << "dist = " << p1.dist(p2) << endl;
}
