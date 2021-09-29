#include <stdio.h>
#include <stdbool.h>
#include <lucky.h>
#include "mathesi.h"

int main() {
    unsigned nb1, nb2, tmp, powCpt, mult = 2;
    bool showPower;
    nb1 = askIntPositive("Enter an unsigned number: ");
    nb2 = askIntPositive("Enter another unsigned number: ");
    int result = gcd(nb1, nb2);
    if (result > 0) {
        printf("GCD of '%d' and '%d': %d", nb1, nb2, gcd(nb1, nb2));
    } else {
        printf("[MATH_ERROR] Can't divide by zero");
    }
    printf("\n");
    return 0;
}