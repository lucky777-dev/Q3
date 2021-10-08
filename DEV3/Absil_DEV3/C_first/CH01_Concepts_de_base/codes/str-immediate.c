#include <stdio.h>

int main()
{
	char * s1 = "Hello"; //length = 5
	char s2[] = "Hello";
	printf("%s\n", s1);
	printf("%s\n", s2);

	char s3[5] = "Hello"; //?!
	char s4[6] = "Hello";
	char s5[20] = "Hello";

	printf("%s|\n", s3);
	printf("%s|\n", s4);
	printf("%s|\n", s5);	
}
