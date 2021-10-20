#ifndef HANOI
#define HANOI
#include <stdbool.h>

struct board {
    int stack_A[4], stack_B[4], stack_C[4];
}; typedef struct board board;

void show(board b);

#endif