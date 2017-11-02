#include "shared.h"

char* HEX_TABLE[16][2] = {
    {"0000", "0"},
    {"0001", "1"},
    {"0010", "2"},
    {"0011", "3"},
    {"0100", "4"},
    {"0101", "5"},
    {"0110", "6"},
    {"0111", "7"},
    {"1000", "8"},
    {"1001", "9"},
    {"1010", "a"},
    {"1011", "b"},
    {"1100", "c"},
    {"1101", "d"},
    {"1110", "e"},
    {"1111", "f"},
};

/**
 * Checks if a given integer can be described as a power of two notation
 * @param number The number
 * @return 0 if not or the exponent number otherwise
 */
int is_power_of_two(int number)
{
    if (number == 0 || number % 2  != 0) {
        return 0;
    } else {
        int iteration = number;
        int exponent = 0;

        while (iteration != 1) {
            if (iteration % 2 != 0) {
                return 0;
            } else {
                iteration = iteration / 2;
                exponent++;
            }
        }

        return exponent;
    }
}
