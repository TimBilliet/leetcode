#include <stdio.h>

int hammingWeight(int n) {
    int amount = 0;
    while (n) {
        amount += n & 1;
        n >>= 1;
    }
}

int main() {
    return 0;
}