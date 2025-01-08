#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)         \
    ((byte) & 0x80 ? '1' : '0'),     \
        ((byte) & 0x40 ? '1' : '0'), \
        ((byte) & 0x20 ? '1' : '0'), \
        ((byte) & 0x10 ? '1' : '0'), \
        ((byte) & 0x08 ? '1' : '0'), \
        ((byte) & 0x04 ? '1' : '0'), \
        ((byte) & 0x02 ? '1' : '0'), \
        ((byte) & 0x01 ? '1' : '0')

int findComplement(int num) {
    if (num == 0)
        return 1;
    int bits = 0;
    int mask = 0b1000000000000000000000000000000;
    while ((mask & num) == 0) {
        bits++;
        mask >>= 1;
    }
    bits = 31 - bits;
    mask = 0;
    for (int i = 0; i < bits; i++) {
        mask <<= 1;
        mask |= 1;
    }
    return num ^ mask;
}

int main() {
    printf("0b" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(findComplement(2100)));
    return 0;
}