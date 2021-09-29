#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool b = true;
    if(b)
      printf("true\n\n");  
    else
      printf("false\n\n");  
    
    if(-1)
      printf("-1 true\n\n");
    else
      printf("-1 false\n\n");
    
    if(0)
      printf("0 true\n\n");
    else
      printf("0 false\n\n");
    
    if(1)
      printf("1 true\n\n");
    else
      printf("1 false\n\n");
    
    if(2)
      printf("2 true\n\n");
    else
      printf("2 false\n\n");
}
