#include <iostream>

using namespace std;

template<class T>
class A
{
	T t;
	public:
		A(T t) : t(t) {}
		friend ostream& operator<<(ostream& out, const A& a)
		{
			return out << a.t;
		}

};


int main()
{
	A<int> a(2);
	cout << a << endl;
}	
