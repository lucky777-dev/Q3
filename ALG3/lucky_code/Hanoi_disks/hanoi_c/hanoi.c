#include "hanoi.h"
#include <stdlib.h>
#include <stdio.h>
#include "util.h"

board b;

int main() {
    unsigned disks_nb;
    printf("Hanoi disks\n\n");
    printf("Enter the number of disks:");
    scanf("%u", &disks_nb);
    b.nb = disks_nb;
    init();
    clearscr();
    show();
    sleep(1);
    printf("Resolved in %d hits.\n", solve(b.nb, b.stack_A, b.stack_B, b.stack_C));
    finish();
    return 0;
}

int solve(int n, int* start, int* inter, int* end) {
    int cpt = 0;
    if (n>=0) {
        cpt++;
        cpt += solve(n-1, start, end, inter);
        //déplacer le disque de taille », n « du socle », départ, « vers le socle », arrivée
        int index_start, index_end;
        for (int i=b.nb-1; i>=0; i--) {
            if (start[i] == n) {
                index_start = i;
            }
            if (end[i] < 0) {
                index_end = i;
            }
        }
        end[index_end] = start[index_start];
        start[index_start] = -1;
        show();
        usleep(50000);
        cpt += solve(n-1, inter, start, end);
    }
    return cpt;
}

void show() {
    clearscr();

    /*
    char tab[4][8] = {{' ', ' ', ' ', 'X', ' ', ' ', ' ', '\0'},
                      {' ', ' ', 'X', 'X', 'X', ' ', ' ', '\0'},
                      {' ', 'X', 'X', 'X', 'X', 'X', ' ', '\0'},
                      {'X', 'X', 'X', 'X', 'X', 'X', 'X', '\0'}
                     };
    */
    printf("\n");
    for (int i = b.nb-1; i >= 0; i--) {
        printf("       ");
        if (b.stack_A[i] >= 0) {
            printf("%s", b.tab[b.stack_A[i]]);
        } else {
            for (int i=0; i < b.nb-1; i++) {
                printf(" ");
            }
            printf("|");
            for (int i=b.nb; i<2*b.nb-1; i++) {
                printf(" ");
            }
        }
        printf("       ");
        if (b.stack_B[i] >= 0) {
            printf("%s", b.tab[b.stack_B[i]]);
        } else {
            for (int i=0; i < b.nb-1; i++) {
                printf(" ");
            }
            printf("|");
            for (int i=b.nb; i<2*b.nb-1; i++) {
                printf(" ");
            }
        }
        printf("       ");
        if (b.stack_C[i] >= 0) {
            printf("%s", b.tab[b.stack_C[i]]);
        } else {
            for (int i=0; i < b.nb-1; i++) {
                printf(" ");
            }
            printf("|");
            for (int i=b.nb; i<2*b.nb-1; i++) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("     -----------   -----------   -----------\n");
}

void init() {
    
    b.stack_A = (int*) malloc(sizeof(int) * b.nb);
    b.stack_B = (int*) malloc(sizeof(int) * b.nb);
    b.stack_C = (int*) malloc(sizeof(int) * b.nb);
    b.tab = (char**) malloc(sizeof(char*) * b.nb);
    for (int i=0; i < b.nb; i++) {
        b.tab[i] = (char*) malloc(sizeof(char) * (2*b.nb));
    }

    for (int i = 0; i < b.nb; i++) {
        b.stack_A[i] = b.nb-1-i;
        b.stack_B[i] = -1;
        b.stack_C[i] = -1;
    }

    b.tab[b.nb][2*b.nb];
    for (int i=0; i<b.nb; i++) {
        for (int j=0; j<b.nb-1-i; j++) {
            b.tab[i][j] = ' ';
        }

        for (int j=b.nb-1-i; j<b.nb+i; j++) {
            b.tab[i][j] = 'X';
        }

        for (int j=b.nb+i; j<2*b.nb-1; j++) {
            b.tab[i][j] = ' ';
        }
        b.tab[i][2*b.nb - 1] = '\0';
    }

}

void finish() {
    free(b.stack_A);
    free(b.stack_B);
    free(b.stack_C);
    for (int i=0; i < b.nb; i++) {
        free(b.tab[i]);
    }
    free(b.tab);
}