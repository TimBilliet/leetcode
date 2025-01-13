#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool isPalindrome(const char* s) {
    int len = strlen(s);
    const char* eind = s + len - 1;
    const char* begin = s;
    while (s < eind) {
        while (!(*s >= 'a' && *s <= 'z' || *s >= 'A' && *s <= 'Z' || *s >= '0' && *s <= '9') && *s) {
            s++;
        }
        while (!(*eind >= 'a' && *eind <= 'z' || *eind >= 'A' && *eind <= 'Z' || *eind >= '0' && *eind <= '9') && eind != begin) {
            eind--;
        }
        printf(" %c %c \n", *eind, *s);
        char lower_s = (*s >= 'a' && *s <= 'z') ? *s : *s + 'a' - 'A';
        char lower_eind = (*eind >= 'a' && *eind <= 'z') ? *eind : *eind + 'a' - 'A';
        if (lower_s != lower_eind && !(*s == 0 && eind == begin)) {
            return false;
        }
        s++;
        eind--;
    }
    return true;
}

int main() {
    printf("ispanlindrome: %d", isPalindrome(".0P"));

    return 0;
}