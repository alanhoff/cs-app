#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "shared.h"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Usage: hex-to-bin 0x01fe3ae09\n");
        return 1;
    }

    const char* bin = argv[1];
    char hex_check[3] = {
        bin[0],
        bin[1],
        '\0'
    };

    if (strcmp(hex_check, "0x") != 0) {
        printf("Please provide a hex string. Example: 0x01fe3ae09\n");
        return 1;
    }

    int output_len = strlen(bin) * 4 - 8;
    int it = 0;
    char output[output_len];
    output[output_len] = '\0';

    for (int i = 2; i < strlen(bin); ++i) {
        int found = 0;
        char match[2] = {tolower(bin[i]), '\0'};

        for (int a = 0; a < sizeof(HEX_TABLE) / sizeof(HEX_TABLE[0]); a++) {
            if (strcmp(match, HEX_TABLE[a][1]) == 0) {
                found = 1;

                output[(it * 4)] = HEX_TABLE[a][0][0];
                output[(it * 4 + 1)] = HEX_TABLE[a][0][1];
                output[(it * 4 + 2)] = HEX_TABLE[a][0][2];
                output[(it * 4 + 3)] = HEX_TABLE[a][0][3];

                break;
            }
        }

        if (found == 0) {
            printf("Unable to convert char %s to binary\n", match);
        }

        it++;
    }

    printf("Result: %s\n", output);
    return 0;
}
