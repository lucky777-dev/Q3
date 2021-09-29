#include <stdio.h>
#include <stdbool.h>
#include "mathesi.h"

int main() {
    int min, max, cpt=0;
    printf("Enter minimum: ");
    scanf("%d", &min);
    printf("Enter maximum: ");
    scanf("%d", &max);
    if (min >= max) {
        printf("Min is not lower than max... bye");
        return 0;
    }
    for (int i = min; i <= max; i++) {
        if (isPrime(i)) {
            printf("%5d", i);
        } else {
            printf("    .");
        }
        if (cpt == 9) {
            printf("\n");
            cpt = 0;
        } else {
            cpt++;
        }
    }
    printf("\n");
    return 0;
}