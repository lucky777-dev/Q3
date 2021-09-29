#include <stdio.h>
#include <stdbool.h>
#include <lucky.h>
#include "mathesi.h"

int main() {
    int nb, tmp, powCpt, mult = 2;
    bool showPower;
    nb = askIntGreater("Enter an unsigned number greater than 1: ", 1);
    showPower = askYN("Should we show power?");
    tmp = nb;
    while(tmp > 1) {
        while((tmp % mult) != 0) {
            mult = nextPrime(mult);
        }
        if (showPower) {
            powCpt = 1;
            tmp = (tmp / mult);
            while(tmp % mult == 0) {
                powCpt++;
                tmp = (tmp / mult);
            }
            if (powCpt > 1) {
                printf("%d^%d", mult, powCpt);
            } else {
                printf("%d", mult);
            }
        } else {
            printf("%d", mult);
            tmp = (tmp / mult);
        }
        if (tmp > 1) {
            printf(" x ");
        }
    }
    printf("\n");
    return 0;
}