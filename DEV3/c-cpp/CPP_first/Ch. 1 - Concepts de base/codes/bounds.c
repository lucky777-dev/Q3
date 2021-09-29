#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main(void)
{   
    printf("INT_MIN    = %+d\n", INT_MIN);
    printf("INT_MAX    = %+d\n", INT_MAX);
    printf("UINT_MAX   = %u\n",  UINT_MAX);
    printf("LONG_MAX   = %ld\n",  LONG_MAX);
    printf("LLONG_MAX  = %lld\n",  LLONG_MAX);
    printf("\n");
 
    printf("FLT_MIN    = %e\n", FLT_MIN);
    printf("FLT_MAX    = %e\n", FLT_MAX);
   	printf("\n");
   	
    printf("DBL_MIN    = %e\n", DBL_MIN);
    printf("DBL_MAX    = %e\n", DBL_MAX);
   	printf("\n");
}