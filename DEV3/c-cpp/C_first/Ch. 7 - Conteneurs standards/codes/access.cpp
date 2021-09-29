#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main()
{
    array<int,5> a = {1, 1, 2, 3, 5};
	vector<int> v = {1, 2, 3, 4, 5};
	list<int> l = {5, 6, 7, 8};
	deque<int> d = {10, 11, 12, 13, 14};

	//direct random acces in constant time
	for(int i = 0; i < 4; i++)
		cout << a[i] << " " << v[i] << " " << d[i] << endl;
	cout << endl;

	cout << l.front() << endl;	
	cout << l.back() << endl;

	auto it = l.begin();
	it++;
	cout << *it << endl;
	it++;
	cout << *it << endl;
}
