#include "hanoi.h"
#include <stdlib.h>
#include <stdio.h>
#include "util.h"

int main() {
    printf("Hello world!\n");
    board b;
    b.stack_A[0] = 3;
    b.stack_A[1] = 2;
    b.stack_A[2] = 1;
    b.stack_A[3] = 0;
    b.stack_B[0] = -1;
    b.stack_B[1] = -1;
    b.stack_B[2] = -1;
    b.stack_B[3] = -1;
    b.stack_C[0] = -1;
    b.stack_C[1] = -1;
    b.stack_C[2] = -1;
    b.stack_C[3] = -1;
    clearscr();
    show(b);
    return 0;
}

void show(board b) {
    char tab[4][8] = {{' ', ' ', ' ', 'X', ' ', ' ', ' ', '\0'},
                      {' ', ' ', 'X', 'X', 'X', ' ', ' ', '\0'},
                      {' ', 'X', 'X', 'X', 'X', 'X', ' ', '\0'},
                      {'X', 'X', 'X', 'X', 'X', 'X', 'X', '\0'}
                     };
    printf("\n");
    for (int i = 3; i >= 0; i--) {
        printf("       ");
        if (b.stack_A[i] >= 0) {
            printf("%s", tab[b.stack_A[i]]);
        } else {
            printf("   |   ");
        }
        printf("       ");
        if (b.stack_B[i] >= 0) {
            printf("%s", tab[b.stack_A[i]]);
        } else {
            printf("   |   ");
        }
        printf("       ");
        if (b.stack_C[i] >= 0) {
            printf("%s", tab[b.stack_A[i]]);
        } else {
            printf("   |   ");
        }
        printf("\n");
    }
    printf("     -----------   -----------   -----------\n");
}