#include <stdio.h>
#include <string.h>
int strStr(char* haystack, char* needle) {
    int consecutive_letters_found = 0;
    int index = 0;
    int len = strlen(needle);
    char* needle_copy = needle;
    while (*haystack) {
        if (*haystack == *needle) {
            consecutive_letters_found++;
            needle++;
            if (consecutive_letters_found == len) {
                return index + 1 - len;
            }
        } else {
            needle = needle_copy;
            for (int i = 0; i < consecutive_letters_found; i++) {
                haystack--;
                index--;
            }
            consecutive_letters_found = 0;
        }
        index++;
        haystack++;
    }
    return -1;
}

int main() {
    printf("%d", strStr("mississippi", "issip"));
    return 0;
}