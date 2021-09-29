#include <vector>
#include <iostream>

using namespace std;

int main()
{	
	vector<int> v(3); //calls defaut cstr once, copy three times
	cout << "size = " << v.size() << " , capacity = " << v.capacity() << " " << v.max_size() << endl;
	for(int i = 0; i < 20 ; i++)
	{
		v.push_back(2);
		cout << "size = " << v.size() << " , capacity = " << v.capacity() << endl;
	}
	cout << endl;	

	v = vector<int>(3);
	v.reserve(5);
	cout << "size = " << v.size() << " , capacity = " << v.capacity() << endl;
	cout << endl;

	v = vector<int>(3);
	v.push_back(2);
	v.reserve(5);
	cout << "size = " << v.size() << " , capacity = " << v.capacity() << endl;
	cout << endl;
	
	cout << v.max_size() << endl;
}
