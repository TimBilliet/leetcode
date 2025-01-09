#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int length_a = strlen(a);
    int length_b = strlen(b);
    int new_str_len = (length_a > length_b ? length_a : length_b) + 1;
    char out[new_str_len + 1];
    out[new_str_len] = '\0';
    int carry = 0;
    int index = 0;
    for (int i = new_str_len - 1; i >= 0; i--) {
        char char_a = (index < length_a && index >= 0) ? a[length_a - 1 - index] : '0';
        char char_b = (index < length_b && index >= 0) ? b[length_b - 1 - index] : '0';
        if (char_a == '1' && char_b == '1' || char_a == '1' && char_b == '0' && carry == 1 || char_a == '0' && char_b == '1' && carry == 1) {
            if (carry && char_b == char_a) {
                out[i] = '1';
            } else {
                out[i] = '0';
            }
            carry = 1;
        } else if (char_a == '1' || char_b == '1' || carry == 1) {
            out[i] = '1';
            carry = 0;
        } else {
            out[i] = '0';
            carry = 0;
        }
        index++;
    }
    char* outt;
    if (out[0] == '0') {
        outt = malloc(sizeof(char) * (new_str_len));
        memcpy(outt, &out[1], new_str_len - 1);
        outt[new_str_len - 1] = '\0';
    } else {
        outt = malloc(sizeof(char) * (new_str_len + 1));
        memcpy(outt, &out[0], new_str_len);
        outt[new_str_len] = '\0';
    }
    return outt;
}

int main() {
    printf("string: %s", addBinary("1010", "10011"));
}