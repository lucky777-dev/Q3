#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//#include <lucky.h>
#include "mathesi.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("error: missing argument\n");
        return -1;
    } else if (argc > 3) {
        printf("error: too many arguments\n");
        return -1;
    } else if (!strcmp(argv[1], "-v") == 0 && !strcmp(argv[1], "--verbose") == 0
            && !strcmp(argv[2], "-v") == 0 && !strcmp(argv[2], "--verbose") == 0) {
        printf("error: bad argument\n\t%15s [integer]\n\t%15s [-v, --verbose]\n", "[-v, --verbose]", "[integer]");
        return -1;
    } else if (atoi(argv[1]) == 0 && atoi(argv[2]) == 0 && (int)(argv[1][0]) != 0 && (int)(argv[2][0]) != 0) {
        printf("error: bad argument\n\t%15s [integer]\n\t%15s [-v, --verbose]\n", "[-v, --verbose]", "[integer]");
        return -1;
    }
    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--verbose") == 0) {
        printf("Verbose!\n");
    }
}