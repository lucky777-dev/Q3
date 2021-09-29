#include <stdio.h>
 
int main()
{
    printf("Strings:\n");
    const char* s = "Hello";
    printf("\t.%10s.\n\t.%-10s.\n\t.%*s.\n", s, s, 10, s);
 
    printf("Characters:\t%c %%\n", 65);
 
    printf("Integers\n");
    printf("\tDecimal:\t%i %d %.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
    printf("\tHexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
    printf("\tOctal:\t%o %#o %#o\n", 10, 10, 4);
 
    printf("Floating point\n");
    printf("\tRounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
    printf("\tPadding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
    printf("\tScientific:\t%E %e\n", 1.5, 1.5);
    printf("\tScientific:\t%g %g\n", 1.002, 0.000007);
    printf("\tHexadecimal:\t%a %A\n", 1.5, 1.5);
}
