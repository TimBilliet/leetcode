#include <stdio.h>
#include <stdlib.h>
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

double myPow(double, int);

int main() {
    printf("x: %lf\n", myPow(2, -2147483648));

    return 0;
}

double myPow(double x, int n) {
    if (n == 0)
        return 1;
    if (x == 1 || n == 1)
        return x;
    if (x == -1)
        return n & 1 == 1 ? -1 : 1;
    if (n == -2147483648)
        return 0;
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    double res = 1;
    while (n > 1) {
        if (n & 1 == 1) {
            res *= x;
            n -= 1;
        }
        x *= x;
        n /= 2;
    }
    return x * res;
}