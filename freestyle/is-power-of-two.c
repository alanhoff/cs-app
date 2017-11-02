#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shared.h"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: is-power-of-two 1234\n");
        return 1;
    }

    char *p;
    int number = 0;

    long conversion = strtol(argv[1], &p, 10);

    if (*p != '\0' || conversion > INT_MAX) {
        fprintf(stderr, "Unable to convert %s to a number\n", argv[1]);
        return 1;
    } else {
        number = conversion;
    }

    int exponent = is_power_of_two(number);

    if (exponent) {
        printf("The number %i is power of two: 2^%i\n", number, exponent);
    } else {
        fprintf(stderr, "The number %i is not power of two\n", number);
        return 1;
    }

    return 0;
}
