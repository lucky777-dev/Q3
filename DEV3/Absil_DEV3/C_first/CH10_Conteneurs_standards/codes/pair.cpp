#include <iostream>
#include <utility>
#include <functional>

using namespace std;

int main()//@cppreference
{
	pair<int, float> p1;
	cout << "Init : " << p1.first << ", " << p1.second << endl;
 
	pair<int, double> p2(42, 0.123);
	cout << "Initialized :" << p2.first << ", " << p2.second << endl;
 
	pair<char, int> p3(p2);
	cout << "Implicitly converted: " << p3.first << ", " << p3.second << endl;

	int n = 1;
	int a[5] = {1, 2, 3, 4, 5};
 
	// build a pair from two ints
	auto p4 = make_pair(n, a[1]);
	cout << "The value of p3 is " << "(" << p4.first << ", " << p4.second << ")" << endl;
 
	// build a pair from a reference to int and an array (decayed to pointer)
	auto p5 = make_pair(ref(n), a);
	n = 7;
	cout << "The value of p4 is " << "(" << p5.first << ", " << *(p5.second + 1) << ")" << endl;
}
