#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1); v.push_back(2); v.push_back(3);
    //vector<int> v = {1,2,3};
    	
	//for(vector<int>::iterator i = v.begin(); i != v.end(); i++)
    for(auto i = v.begin(); i!= v.end(); i++)
		cout << *i << " ";
	cout << endl;

	for(int elem : v) //same
		cout << elem << " ";
    cout << endl;
    
    //reverse order
    for(auto i = v.rbegin(); i!= v.rend(); i++)
		cout << *i << " ";
	cout << endl;
    
    for(int& elem : v)
        elem = 4;        
    
    //lambda
    for_each(v.begin(), v.end(), [](int i) { cout << i<< " "; });
    cout << endl;
}
