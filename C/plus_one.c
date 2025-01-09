#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 0;
    int oneadded = 0;
    int new_length = digitsSize;
    for (int i = digitsSize - 1; i >= 0; i--) {
        printf("%d \n", digits[i]);
        if (digits[i] == 9) {
            if (oneadded == 0) {
                digits[i] = 0;
                carry = 1;
                oneadded = 1;
            } else if (carry) {
                digits[i] = 0;
                carry = 1;
            }
        } else {
            if (carry) {
                digits[i]++;
            }
            if (oneadded == 0) {
                digits[i]++;
                oneadded = 1;
            }
            carry = 0;
        }
        if (i == 0 && carry) {
            new_length++;
        }
    }
    *returnSize = new_length;
    int* ret = malloc(new_length * sizeof(int));
    if (new_length > digitsSize) {
        memcpy(ret + 1, digits, digitsSize * sizeof(int));
        ret[0] = 1;
    } else {
        memcpy(ret, digits, digitsSize * sizeof(int));
    }
    return ret;
}

int main() {
    int dig[] = {8, 9, 9, 9};
    int retsize;
    int* out = plusOne(dig, sizeof(dig) / sizeof(dig[0]), &retsize);
    printf("size %d\n", retsize);
    for (int i = 0; i < retsize; i++) {
        printf("getal: %d\n", out[i]);
    }
    return 0;
}