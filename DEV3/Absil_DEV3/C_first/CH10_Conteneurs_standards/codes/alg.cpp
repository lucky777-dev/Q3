#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v = {5,6,3,3,4,1,2};
	list<int> l;	

	copy(v.begin(), v.end(), back_inserter(l));
	cout << "list = ";
	for(int e : l)
		cout << e << " ";
	cout << endl << endl;

	equal(v.begin(),v.end(),l.begin()) ? cout << "true" : cout << "false";
	cout << endl;

	cout << count(v.begin(),v.end(), 3) << endl;

	auto i = find(v.begin(), v.end(), 3);
	cout << *i << endl;

	sort(v.begin(), v.end());
	for(int e : v)
		cout << e << " ";
	cout << endl;

	for_each(v.begin(), v.end(), 
		[](int i) 
		{ 
			cout << "Hello " << i << endl; 
		} 
	);
}
