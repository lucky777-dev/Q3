#include <iostream>
#include <map>

using namespace std;

int main()
{	
	map<int, float> m;

	for(int i = 0; i < 3; i++)
		m[i] = i + 0.5;

	for(auto e : m)
		cout << "( " << e.first << " , " << e.second << " )" << endl;
	cout << endl;

	cout << "m[5] = " << m[5] << endl;

	for(auto e : m)
		cout << "( " << e.first << " , " << e.second << " )" << endl;
	cout << endl;

	cout << (*m.find(2)).second << endl;
	
	if(m.find(6) != m.end())
		cout << (*m.find(6)).second << endl;
	else
		cout << "Key '6' does not exist" << endl;	
	
	for(auto e : m)
		cout << "( " << e.first << " , " << e.second << " )" << endl;
	cout << endl;
}
