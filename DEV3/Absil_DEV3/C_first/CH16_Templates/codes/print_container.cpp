#include <iostream>
#include <vector>
#include <list>

using namespace std;

//suppose que c déclare begin() et end(), et que les trucs retournés déclarent *, ++ préfixé et !=
template<class Container>
void print(const Container& c)
{
	for(const auto & o : c)
		cout << o << " ";
}

struct A {};

int main()
{
	vector<int> v = {1,2,3,4,5};
	list<double> l = {1.1, 2.2, 3.3, 4.4, 5.5};

	print(v);
	cout << endl;

	print(l);
	cout << endl;

	//A a;
	//print(a);
}
