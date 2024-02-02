#include <stdio.h>
//strlen מימוש של
int myStrlen( char* str) {
    char* s;
    for (s = str; *s; ++s);
    return s - str;
}
//strcpy מימוש של 
char* myStrcpy(char* destination, const char* source) {
    char* ptr = destination;

    while (*source != '\0') {
        *ptr = *source;
        source++;
        ptr++;
    }

    *ptr = '\0';

    return destination;
}
//strcmp מימוש של  
int myStrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
