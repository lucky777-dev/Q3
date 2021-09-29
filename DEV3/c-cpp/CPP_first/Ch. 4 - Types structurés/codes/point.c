#include <stdio.h>
#include <math.h>

struct point
{
	double x, y;	
};

struct point2
{
	double x, y;	
};


typedef struct point point;
typedef struct point2 point2;

double dist(point p1, point p2)
{	
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); //add -lm compile option
}

int main()
{
	point p;

	printf("%f %f\n", p.x, p.y);//undefined

	p.x = p.y = 0;

	point p2 = {1, 1}; //try with = {1}
	printf("%f %f\n", p2.x, p2.y);

	printf("%f\n", dist(p, p2));

	point2 brol;
    
    //point p3 = (point)brol;
	//dist(p1, brol); //no conversion
}
