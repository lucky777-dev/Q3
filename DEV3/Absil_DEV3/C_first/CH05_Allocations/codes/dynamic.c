#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x, y;
} 
Point;

void print_point(Point p)
{
    printf("(%d,%d)\n", p.x, p.y);
}

int main()
{
    Point * p = (Point*) malloc(sizeof(Point));
    p->x = 1; p->y = 2;   
    print_point(*p);
    
    free(p);
    print_point(*p);
    
    Point * p2 = NULL;
	Point * pp2 = NULL;
    
    Point p3;

	{
		p2 = (Point*) malloc(sizeof(Point)); 
        p2->x = 3; p2->y = 4;
		print_point(*p2);
		pp2 = p2;

		p3 = *p2;		
		//free(p2); //uncomment
	}

    print_point(*p2);
    print_point(*pp2);
    print_point(p3);	
}
