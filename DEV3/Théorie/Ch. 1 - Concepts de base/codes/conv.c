#include <stdio.h>
#include <stdbool.h>

int main()
{
	int i1 = 3;
	int i2 = 2.5;
	double d1 = i1;
	double d2 = 2.5f;

	unsigned u1 = i1;
	unsigned u2 = -1;

	printf("ints : %d %d\n", i1, i2);
	printf("floating point : %.2f %.2f\n", d1, d2);
	printf("unsigned : %u %u\n", u1, u2);

	printf("Sizeof int | double -- %lu %lu\n", sizeof(int), sizeof(double));

	printf("Sizeof 2 * 3L + 5.0 : %lu\n", sizeof(2 * 3L + 5.0));

	printf("%d\n", (0 == true));
	printf("%d\n", (1 == true));
	printf("%d\n", (2 == true));
}
