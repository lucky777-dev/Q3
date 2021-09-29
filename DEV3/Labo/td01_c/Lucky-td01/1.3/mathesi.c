#include "mathesi.h"

#include <stdio.h>

bool isPrime(unsigned nb) {

    if (nb == 1 || nb%2 == 0) {
        return false;
    }

    //i * i < nb
    //faster than:
    //i < sqrt(nb)
    for (int i = 3; i * i < nb; i+=2) {
        if (nb%i == 0) {
            return false;
        }
    }

    return true;
}

int nextPrime(unsigned nb) {
    while(true) {
        nb++;
        if (isPrime(nb)) {
            return nb;
        }
    }
}