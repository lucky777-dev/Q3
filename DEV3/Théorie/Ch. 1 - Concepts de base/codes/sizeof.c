#include "stdio.h"
#include "limits.h"

int main()
{
	printf("Size of char             : %lu bytes\n", sizeof(char));
	printf("Size of short            : %lu bytes\n", sizeof(short));
	printf("Size of int              : %lu bytes\n", sizeof(int));
    printf("Size of unsigned         : %lu bytes\n", sizeof(unsigned));
	printf("Size of long int         : %lu bytes\n", sizeof(long int));
	printf("Size of long long int    : %lu bytes\n", sizeof(long long int));
	printf("Size of adress           : %lu bytes\n", sizeof(int*));
	printf("Size of float            : %lu bytes\n", sizeof(float));
	printf("Size of double           : %lu bytes\n", sizeof(double));
	printf("Size of long double      : %lu bytes\n", sizeof(long double));
    
    unsigned i = -1;
    printf("%u\n", i);
    if(i == UINT_MAX)
        printf("Two complement\n");
    else
        printf("Sth else\n");
}
