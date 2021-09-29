#include "point-decl-impl.h"

#include <cmath>

point::point(int x, int y)
{
    this->x = x;
    this->y = y;
}

double point::dist(point p)
{
    return sqrt((x - p.x)*(x - p.x)+(y - p.y)*(y - p.y));
}