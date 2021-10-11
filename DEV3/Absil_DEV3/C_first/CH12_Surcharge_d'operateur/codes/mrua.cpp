#include <iostream>

using namespace std;

class MRUA
{
	long double x0, t0, v0, a;
	
	public :
		MRUA(long double x0 =0, long double t0 = 0, long double v0 = 0, long double a = 9.81)
			: x0 ( x0 ) , t0 ( t0 ) , v0 ( v0 ) , a ( a )
		{}
		
		long double operator () (long double t) 
        { 
            long double dt = (t - t0);
            return x0 + v0 * dt + 0.5 * dt * dt;
        }
};

inline long double operator "" _ms(long double x) { return 0.001 * x; }
inline long double operator "" _s(long double x) { return x; }
inline long double operator "" _min(long double x) { return 60 * x; }
inline long double operator "" _h(long double x) { return 3600 * x; }

int main()
{
    MRUA mrua;
    cout << "Position after 1 millisecond is " << mrua(1.0_ms) << " meters" << endl;
    cout << "Position after 1 second is " << mrua(1.0_s) << " meters" << endl;
    cout << "Position after 1 minute is " << mrua(1.0_min) << " meters" << endl;
    cout << "Position after 1 hour is " << mrua(1.0_h) << " meters" << endl;
}
