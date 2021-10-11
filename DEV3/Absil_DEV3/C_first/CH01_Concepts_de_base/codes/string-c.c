#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "Hello ";
	char s2[] = "World";

	printf("Length = %lu chars, size = %lu bytes\n", strlen(s1), sizeof(s1));
	printf("Length = %lu chars, size = %lu bytes\n", strlen(s2), sizeof(s2));
	printf("Lexicographic comparison between s1 and s2: %d\n", strcmp(s1, s2));

	for(long i = 0; i < strlen(s1); i++)
		printf("%c", s1[i]);
	for(long i = 0; i < strlen(s2); i++)
		printf("%c", s2[i]);
	printf("\n");

	//strcpy(s2, s1); //wrong
    //printf("%s\n", s2);
	//strcpy(s1, s2); //also wrong    
    //printf("%s\n", s1);


    /*
	char result[20]; //try with other values

	strcpy(result, s2);	
	printf("%s|\n", result);
    
	strcpy(result, s1);
	printf("%s|\n", result);    
    */

	//strcat(s2, s1); //still wrong    
	//strcat(s1, s2); //again, wrong
    
	char result2[strlen(s1) + strlen(s2) + 1]; //why + 1 ?
	strcpy(result2, s1);
	strcat(result2, s2);
	printf("%s\n", result2);
}

