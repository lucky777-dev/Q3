#include <stdio.h>

void print_str(const char* s)
{
	const char* pt = s;
	while(*pt != '\0')
	{
		printf("%c", *pt);
		pt++;
	}
}

int main()
{
	const char* s = "Hello World!\n";
	print_str(s);
}
