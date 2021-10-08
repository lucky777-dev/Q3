#include <iostream>
#include <map>

using namespace std;

void print(const map<char, int> &m)
{
	cout << "Map : " << endl;
	for(auto e : m)
		cout << "( " << e.first << " , " << e.second << " )" << endl;
	cout << endl;
}

int main()
{
	map<char, int> m;
	print(m);

	m['S'] = 5; m['C'] = 10;
	m['s'] = 2;
	print(m);
    
	m['S'] = m['D'];
	print(m);
    
    /*
    if(m.find('D') != m.end())
        m['S'] = m['D'];
    else
        cout << "m['D'] does not exist" << endl;
    */
    
    /*
    auto it = m.find('D'); //returns an iterator to a pair
    if(it != m.end())
        m['S'] = (*it).second;
    else
        cout << "m['D'] does not exist" << endl;
    */
}
