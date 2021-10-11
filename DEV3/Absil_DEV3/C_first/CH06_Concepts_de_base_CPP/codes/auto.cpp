#include <iostream>
#include <cmath>

using namespace std;

auto f(int i)
{
	switch(i)
	{
		case 1 : return sqrt(i);
		case 2 : return cos(i);
		default : return i + 0.;
	}	
}

int main()
{
	auto a = 3 + 4;
	cout << a << " of type " << typeid(a).name() << endl;

	decltype(a) b; 
	b = 7.2;
	cout << b << " of type " << typeid(b).name() << endl;

	for(int i = 0; i <=3; i++)
	    cout << f(i) << " of type " << typeid(f(i)).name() << endl;

	auto list = {1, 2};
	cout << "Type of list : " << typeid(list).name() << endl;
}