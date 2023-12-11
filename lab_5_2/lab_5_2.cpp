#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void analyzeString(char* str, int* results) {
    int words = 0, digits = 0, spaces = 0, controls = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            if (isdigit(str[i])) {
                digits++;
            }
            else {
                while (isalnum(str[i]) && i < len) {
                    i++;
                }
                words++;
                i--;
            }
        }
        else if (isspace(str[i])) {
            spaces++;
        }
        else if (iscntrl(str[i])) {
            controls++;
        }
    }

    results[0] = words;
    results[1] = digits;
    results[2] = spaces;
    results[3] = controls;
}

int compare(const void* a, const void* b) {
    const int* aa = (const int*)a;
    const int* bb = (const int*)b;
    return aa[0] - bb[0];
}

int main() {
    setlocale(0, "Russian");
    char** lines = NULL;
    char input[100];
    int lineCount = 0;


    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "and\n") == 0) {
            break;
        }
        lines = (char**)realloc(lines, (lineCount + 1) * sizeof(char*));
        lines[lineCount] = (char*)malloc(strlen(input) + 1);
        strcpy(lines[lineCount], input);
        lineCount++;
    }

    int** results = (int**)malloc(lineCount * sizeof(int*));
    for (int i = 0; i < lineCount; i++) {
        results[i] = (int*)malloc(4 * sizeof(int));
        analyzeString(lines[i], results[i]);
    }

    qsort(results, lineCount, sizeof(int*), compare);

    for (int i = 0; i < lineCount; i++) {
        printf("%s - (Слова: %d, Цифры: %d, Пробелы: %d, Cимволы: %d)\n",
            lines[i], results[i][0], results[i][1], results[i][2], results[i][3]);
        free(lines[i]);
        free(results[i]);
    }
    free(lines);
    free(results);

    return 0;
}