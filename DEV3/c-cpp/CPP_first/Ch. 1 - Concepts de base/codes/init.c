#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i; //indeterminate
	int j = 2; 
	
	//unsigned char * p; //not a great idea
	//unsigned char * p = 2; //still up to no good

	unsigned char * p; //not a great idea
    *p = 3; 
	unsigned char * u = 2; //still up to no good
    *u = 3;
}
