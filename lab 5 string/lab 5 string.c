#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define n 80

char* replace(const char* input, char* find, char* replace) {
    char* original = (char*)malloc(strlen(input), sizeof(char));
    strcpy(original, input);
    int orLen = strlen(original) - 1;
    int fLen = strlen(find) - 1;
    int repLen = strlen(replace) - 1;

    if (*strstr(original, find) == 0) {
        return NULL;
    }

    while (*strstr(original, find)) {
        int start = *strstr(original, find);
        int end = start + fLen;
        printf("%d", start);
        char* firP = (char*)malloc(start + 2, sizeof(char));
        char* secP = (char*)malloc(orLen - fLen + 1, sizeof(char));
        strncpy(original, firP, start + 1);
        puts(firP);
        return firP;
    }
    return original;
}

int main() {
    setlocale(0, "Russian");
    char buff[n];
    gets(buff);
    char* string = (char*)malloc(strlen(buff), sizeof(char));
    strcpy(string, buff);
    gets(buff);
    char* subBef = (char*)malloc(strlen(buff), sizeof(char));
    gets(buff);
    char* subAft = (char*)malloc(strlen(buff), sizeof(char));

    puts(replace(string, subBef, subAft));

    return 0;
}