#include <iostream>

using namespace std;

template<class T>
class A; // forward declare to make function declaration possible
 
template<class T> // declaration
ostream& operator<<(ostream&, const A<T>&);
 
template<class T>
class A 
{
	T t;

	public:
	    A(T t) : t(t) {}

    // refers to a full specialization for this particular T 
    friend std::ostream& operator<< <> (std::ostream&, const A&);
};
 
// definition
template<typename T>
ostream& operator<<(ostream& out, const A<T>& a)
{
    return out << a.t;
}
 
int main()
{
	A<int> a(2);
	cout << a << endl;
}
