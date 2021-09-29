#include <iostream>

using namespace std;

class vector2d
{
    double _x, _y;
    
    public:
        vector2d(double x = 0, double y = 0) : _x(x), _y(y) 
        {}
    
        inline double x() const { return _x; }
        inline double y() const { return _y; }                        
    
        vector2d& operator +=(const vector2d& v)
        {
            _x += v._x;
            _y += v._y;
            
            return *this;
        }
    
        friend vector2d operator + (vector2d v1, const vector2d& v2)
        {
            v1 += v2;
            return v1;
        }
    
        friend ostream& operator <<(ostream& out, const vector2d& v)
        {
            return out << "(" << v._x << " , " << v._y << ")";
        }
};

int main()
{
    vector2d v1(1,2); vector2d v2(3,4);
    cout << v1 << " " << v2 << endl;
    
    cout << (v1 + v2) << endl;
    v1 += v2;
    cout << v1 << endl;
}
