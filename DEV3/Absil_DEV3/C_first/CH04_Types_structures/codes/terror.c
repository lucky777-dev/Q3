#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str
{
    unsigned length;
    char* chars;
};

typedef struct str str;

str init_str(str* s, unsigned length)
{    
    s->length = length;
    s->chars = (char*) calloc(length + 1, sizeof(char));    
};

str free_str(str* s)
{
    free(s->chars);
}

void terror(str s)
{
    s.length = 42;
    free_str(&s);
}

int main()
{
    str s;
    init_str(&s, 5);
    strcpy(s.chars, "Hello");
    
    printf("%s\n", s.chars);
    
    terror(s);
    printf("%s\n", s.chars);    
}
