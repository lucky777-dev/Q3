#ifndef POINT_HEADER
#define POINT_HEADER

class point
{
	double x, y;

	public:
		point(int x, int y);
		inline double getX() const;
		inline double getY() const;
		double dist(const point& p);
};

double point::getX() const
{
    return x;
}

double point::getY() const
{
    return y;
}

#endif