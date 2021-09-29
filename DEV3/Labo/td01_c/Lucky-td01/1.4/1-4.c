#include <stdio.h>
#include <stdbool.h>
#include <lucky.h>
#include "mathesi.h"

int main() {
    unsigned nb1, nb2, tmp, powCpt, mult = 2;
    bool showPower;
    int result;
    nb1 = askIntPositive("Enter an unsigned number: ");
    nb2 = askIntPositive("Enter another unsigned number: ");
    if (nb1 < nb2) {
        result = gcd(nb2, nb1);
    } else {
        result = gcd(nb1, nb2);
    }
    if (result > 0) {
        printf("GCD of '%d' and '%d': %d", nb1, nb2, gcd(nb1, nb2));
    } else {
        printf("[MATH_ERROR] Can't divide by zero");
    }
    printf("\n");
    return 0;
}