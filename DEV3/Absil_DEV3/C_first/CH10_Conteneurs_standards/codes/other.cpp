#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{	
	int x, y;
	
	public:
		point(int x = 0, int y = 0) : x(x), y(y) {}

		bool operator ==(const point& p) const 
		{
			return x == p.x && y == p.y; 
		}
};

int main()
{
	vector<int> v1 = {1,2,3,6};
	vector<int> v2 = {2,3,4,5,0};

	cout << ((v1 < v2) ? "v1 < v2" : "v2 >= v1") << endl;

	v1.swap(v2);
	for_each(v1.begin(), v1.end(), [](int& i) { cout << i << " "; }); 
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int& i) { cout << i << " "; }); 
	cout << endl;

	point p1(1,1);
	point p2(2,2);
	vector<point> vp1; vp1.push_back(p1); vp1.push_back(p2);
	vector<point> vp2; vp2.push_back(p1); vp2.push_back(p2);	
	cout << ((vp1 == vp2) ? "vp1 == vp2" : "vp1 != vp2") << endl;

	vp1.clear();
}
