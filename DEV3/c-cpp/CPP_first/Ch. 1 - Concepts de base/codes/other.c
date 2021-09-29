#include <stdio.h>
#include <stdint.h>

int main()
{       
    char a = 'a';
    printf("Char : %c\n", a);
    char ee = 'é';
    printf("Char : %c\n", ee);    
    
    int8_t i8 = 0;
    int16_t i16 = 0;
    int32_t i32 = 0;
    int64_t i64 = 0;
    printf("%zu %zu %zu %zu\n", sizeof(i8), sizeof(i16), sizeof(i32), sizeof(i64));
    
    int i = 2;
    int * addr = &i;
    printf("i = %d stored at address %p\n", i, addr);
}
