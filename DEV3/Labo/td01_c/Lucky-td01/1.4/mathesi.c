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

int gcd(unsigned nb1, unsigned nb2) {
    if (nb1 == 0 && nb2 == 0) {
        return -1;
    } else if (nb2 == 0) {
        return nb1;
    } else if(nb1 == 0) {
        return nb2;
    }
    int result;
    while(nb2 > 0) {
        printf("%d = %d x %d + %d | ", nb1, nb2, (nb1 / nb2), (nb1 % nb2));
        result = nb2;
        nb2 = (nb1 % nb2);
        nb1 = result;
    }
    return result;
}