#include <stdio.h>
#include <string.h>
#include <math.h>

const char* HEX_TABLE[16][2] = {
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

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Please provide a single argument");
        return 1;
    }

    char* bin = argv[1];
    int output_len = ceil(strlen(argv[1]) / 4);
    char output[output_len + 1];
    output[output_len + 1] = '\0';
    int it = output_len;

    for(int i = strlen(bin) - 1; i >= 0; i -= 4) {
        char last_four[5] = {
            i - 3 < 0 ? '0' : bin[i - 3],
            i - 2 < 0 ? '0' : bin[i - 2],
            i - 1 < 0 ? '0' : bin[i - 1],
            bin[i],
            '\0'
        };

        int found = 0;

        for(int a = 0; a < 16; a++) {
            if(strcmp(last_four, HEX_TABLE[a][0]) == 0) {
                found = 1;
                output[it] = *HEX_TABLE[a][1];
            }
        }

        if (found == 0) {
            printf("Unable to convert %s to hex", last_four);
            return 1;
        }

        it--;
    }

    printf("Result: 0x%s", output);
    return 0;
}
