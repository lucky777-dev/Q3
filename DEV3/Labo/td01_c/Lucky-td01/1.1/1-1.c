#include <stdio.h>
#include "mathesi.h"

int main() {

    int nb;
    printf("Enter a number: ");
    scanf("%d", &nb);

    while(nb != 0) {
        if (isPrime(nb)) {
            printf("%d is prime!\n", nb);
        } else {
            printf("%d is NOT prime!\n", nb);
        }
        printf("Enter a number: ");
        scanf("%d", &nb);
    }
}