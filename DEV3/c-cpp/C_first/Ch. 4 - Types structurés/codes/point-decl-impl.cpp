#include "point-decl-impl.h"

#include <cmath>

point::point(int x, int y) : x(x), y(y)
{    
}

double point::dist(const point& p)
{
    return std::sqrt((x - p.x)*(x - p.x)+(y - p.y)*(y - p.y));
}