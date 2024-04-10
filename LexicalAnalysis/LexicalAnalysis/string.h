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


char* my_strchr(const char* str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}

char* my_strpbrk(const char* str, const char* delimiters) {
    while (*str != '\0') {
        if (my_strchr(delimiters, *str) != NULL) {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}

char* my_strtok(char* str, const char* delimiters) {
    static char* nextToken = NULL;
    if (str != NULL) {
        nextToken = str;
    }
    else if (nextToken == NULL) {
        return NULL;
    }

    char* tokenStart = nextToken;
    char* delimiter = my_strpbrk(nextToken, delimiters);
    if (delimiter != NULL) {
        *delimiter = '\0';
        nextToken = delimiter + 1;
    }
    else {
        nextToken = NULL;
    }

    return tokenStart;
}