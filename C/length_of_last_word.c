#include <stdio.h>
int lengthOfLastWord(char* s) {
    char vorige_char = 0;
    char* index_woord = s;
    char* eind_index_woord;
    int index = 0;
    while (*s) {
        if ((vorige_char == ' ' || vorige_char == 0) && *s != ' ') {
            index_woord = s;
        } 
        vorige_char = *s;
        s++;
    }
    while (*index_woord != ' ' && *index_woord != 0) {
        index_woord++;
        index++;
    }
    return index;
}

int main() {
    printf("len: %d", lengthOfLastWord(" fly me   to   the moon  "));
    return 0;
}