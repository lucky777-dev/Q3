#include "dist.h"
#include <cmath>

namespace math
{
	double dist(double x1, double y1, double x2, double y2)	
	{
		return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}
}
