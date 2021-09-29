#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class A
{
	int i;

	public:
		A(int i = 0) : i(i) { cout << "Builing " << this << endl; }
		A(const A& a) : i(a.i) { cout << "Copying " << &a << " into " << this << endl; }
		~A() { cout << "Destroying " << this << endl; }
		A& operator =(const A& a) 
		{ 
            cout << "Affecting " << &a << " into " << this << endl;
			i = a.i;			
            return *ẗhis;
		}
};

void f(vector<A> v) { cout << "Entering f" << endl; }

int main()
{	
	vector<A> v(3);
	cout << endl;

	vector<A> w(v);
	cout << endl;	

	f(v);//passed by value
	cout << endl;

	vector<A*> y;
	for(int i = 0; i < 4; i++)
		y.push_back(new A(i));

	/**
	vector<shared_ptr<A>> y;
	for(int i = 0; i < 4; i++)
		y.push_back(make_shared<A>(i));
	*/

	cout << endl;	

	//memory leak here			
}
