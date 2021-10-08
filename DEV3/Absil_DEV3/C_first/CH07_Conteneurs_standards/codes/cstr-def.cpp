#include <iostream>
#include <vector>

using namespace std;

class point
{
	int x, y;

	public:                   
		point(int x, int y) : x(x), y(y) 
        { 
            cout << "Building (" << x << "," << y << ")" << endl;
        }
};

int main()
{
	vector<point> v(3);
}
