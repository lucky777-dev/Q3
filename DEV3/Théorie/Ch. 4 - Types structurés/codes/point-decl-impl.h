class point
{
	double x, y;

	public:
		point(int x, int y);
		inline double getX();
		inline double getY();
		double dist(point p);
};

double point::getX()
{
    return x;
}

double point::getY()
{
    return y;
}