#include <iostream>
#include <random>

using namespace std;

double random_double(double min, double max)
{    
    static random_device rd;
    static mt19937 rng;

    uniform_real_distribution<double> dist(min, max);    
    return dist(rng);    
}

int main()
{
    cout << random_double(0, 1) << endl;
}
