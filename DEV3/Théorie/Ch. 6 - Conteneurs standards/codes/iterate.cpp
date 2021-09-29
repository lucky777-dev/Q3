#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1); v.push_back(2); v.push_back(3);
	vector<int>::iterator i;
	for(i = v.begin(); i != v.end(); i++)
		cout << *i << " ";
	cout << endl;

	for(int elem : v) //identique
		cout << elem << " ";
	cout << endl;
}
