#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	list<double> l = {2.5, 3.5, 6.5, 7.5};

	auto it1 = l.begin();
	it1++;it1++;
	l.insert(it1, 1.5);
	l.insert(it1, 10, -1);

	for_each(l.begin(), l.end(), [](double& d) { cout << d << " ";});
	cout << endl;

	vector<double> v = {1.1, 2.2, 3.3};
	it1++;it1++;it1++;
	l.insert(it1, v.begin(), v.end());

	for_each(v.begin(), v.end(), [](double& d) { cout << d << " ";});
	cout << endl;

	it1 = l.begin();
	for(int i = 0; i < 5; i++)
		it1++;
	l.insert(it1, v.begin(), v.end());

	for_each(l.begin(), l.end(), [](double& d) { cout << d << " ";});
	cout << endl;

	it1 = l.begin();
	auto it2 = l.end();
	it2--;it2--;
	for(int i = 0; i < 9; i++)
		it1++;
	l.erase(it1, it2);
	
	for_each(l.begin(), l.end(), [](double& d) { cout << d << " ";});
	cout << endl;
}
