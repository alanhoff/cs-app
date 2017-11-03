#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shared.h"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: power-of-two-to-hex 1234\n");
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

    if (!exponent) {
        fprintf(stderr, "The number %i is not power of two\n", number);
        return 1;
    }

    int number_of_zeros = 0;
    int divisible_by_four = exponent % 4 == 0;

    while ((number_of_zeros * 4) < exponent) {
        number_of_zeros++;
    }

    if (!divisible_by_four) {
        number_of_zeros--;
    }

    int hex_digit = 1;

    if ((0 + (4 * number_of_zeros)) == exponent) {
        hex_digit = 1;
    } else if ((1 + (4 * number_of_zeros)) == exponent) {
        hex_digit = 2;
    } else if ((2 + (4 * number_of_zeros)) == exponent) {
        hex_digit = 4;
    } else if ((3 + (4 * number_of_zeros)) == exponent) {
        hex_digit = 8;
    } else {
        fprintf(stderr, "Something went wrong\n");
        return 1;
    }

    char hex_zeroes[number_of_zeros + 1];
    hex_zeroes[number_of_zeros] = '\0';

    for (int i = 0; i < number_of_zeros; ++i) {
        hex_zeroes[i] = '0';
    }

    printf("The number %i in hex is: 0x%i%s\n", number, hex_digit, hex_zeroes);

    return 0;
}
