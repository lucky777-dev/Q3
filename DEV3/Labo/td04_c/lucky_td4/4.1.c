#include "4.1.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "mathesi.h"

int main() {
    printf("Hello world!\n");
    unsigned nbElem = 0;
    unsigned* decomposition = primeFactorsA(&nbElem, 777);
    free(decomposition);
    printf("Memory released: success\nended\n");
    return 0;
}

unsigned* primeFactorsA(unsigned* count, unsigned number) {
    unsigned* primes = malloc(number * sizeof(unsigned));
    if (primes == NULL) {
        printf("error: 'primes' pointer is NULL!\n");
        exit(1);
    }

    *count = 0;
    unsigned mult = 2;

    while(number > 1) {
        while((number % mult) != 0) {
            mult = nextPrime(mult);
        }
        while(number % mult == 0) {
            primes[*count] = mult;
            *count++;
            number = (number / mult);
        }
    }

    primes = realloc(primes, (*count * sizeof(unsigned)));
    return primes;
}