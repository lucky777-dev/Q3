#include <iostream>
using namespace std;

class point
{
	int x, y;
	
	public:
		point(int abs = 0, int ord = 0)  : x(abs), y(ord) {}
		
		friend bool coincide(const point &, const point &);
};

int main()
{
	point a(1,0), b(1), c;
	if(coincide(a,b))
		cout << "a coincide avec b" << endl;
	else
		cout << "a et b sont différents" << endl;
		
	if(coincide(a,c))
		cout << "a coincide avec c" << endl;
	else
		cout << "a et c sont différents" << endl;
}

bool coincide(const point &p, const point &q)
{
	return ((p.x == q.x) && (p.y == q.y));
}
