#include <iostream>

using namespace std;

class point
{
	protected:
		int x, y;
	
	public:
		point(int x = 0, int y = 0) : x(x), y(y) {}

		friend ostream& operator <<(ostream& out, const point& p);

		virtual void print()
		{
			cout << "( " << x << " , " << y << " )" << endl;		
		}		
};

ostream& operator<<(ostream& out, const point& p)
{
	out << "( " << p.x << " , " << p.y << " )";
	return out;
}

class pointcol : public point
{
	short r, g, b;
	
	public:
		pointcol(int x = 0, int y = 0, int r = 255, int g = 255, int b = 255) 
			: point(x,y), r(r), g(g), b(b) {}
	
		friend ostream& operator <<(ostream& out, const pointcol& p);			

		void print()
		{		
			cout << "( " << x << " , " << y << " ) - color " << r << " " << g << " " << b << endl;
		}
};

ostream& operator<<(ostream& out, const pointcol& p)
{
	out << "( " << p.x << " , " << p.y << " ) - color " << p.r << " " << p.g << " " << p.b;
	return out;
}

int main()
{	
	point p (1,2);
	pointcol pc (3,4,128,255,255);	
	cout << p << endl;
	cout << pc << endl;
	
	p = pc; //pp truncated : p is "really" a point
	//pc = p; // ko
	//pc = static_cast<pointcol>(p); //ko	
	cout << p << endl;
	cout << pc << endl;

	p  = point(1,2); point& rp = p;
	pc = pointcol(3,4,128,255,255); pointcol& rpc = pc;

	rp = rpc; //no truncation
	pointcol& rpc2 = static_cast<pointcol&>(rp);// ok, but incoherent result for r, g, b

	cout << endl;

	cout << rp << endl;
	cout << rpc << endl;
	cout << rpc2 << endl;
	cout << endl;

	rp.print();
	rpc.print();
	rpc2.print();
	cout << endl;
		
	point * ptp = new point(1,2);
	pointcol * ptpc = new pointcol(3,4,128,255,255);

	ptp = ptpc; //no truncation
	cout << (*ptp) << endl;
	cout << (*ptpc) << endl;

	ptp = new point(1,2);
	//ptpc = ptp; //ko	
	//ptpc = static_cast<pointcol*>(ptp);//ok, but seg fault
	
	cout << (*ptp) << endl;
	cout << (*ptpc) << endl;

	if(pointcol * converted = dynamic_cast<pointcol*>(ptp))
	{
		cout << (*ptp) << endl;
		cout << (*ptpc) << endl;
	}
	else
		cout << "You cannot convert this point to a pointcol" << endl;	
	
	delete ptp;
	delete ptpc;	
}


