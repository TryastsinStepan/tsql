#include "parser.h"

char** parseLineByLine() {
    char** lines = fileread;
    int i = 0;
    int c = 0;
    int counter = 0;
    char** line = allocMemory();
    while (lines[i] != NULL && i < 100) {
        char* str = lines[i];
        int j = 0;
        int spaceEncountered = 0; // Флаг для отслеживания встречи пробела
        while (*str != '\0') {
            if (*str != ' ') {
                line[c][j] = *str;
                j++;
                spaceEncountered = 0; // Сброс флага, если символ не пробел
            }
            else if (spaceEncountered == 0) { // Если это первый пробел в серии
                line[c][j] = *str;
                j++;
                spaceEncountered = 1; // Установка флага
            }
            str++;
        }
        line[c][j] = '\0';
        c++;
        i++;
        counter++;
        count = counter;
    }
    return line;
}

char** allocMemory() {
    char** line = (char**)malloc(100 * sizeof(char*)); 
    if (line == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 100; i++) {
        line[i] = (char*)malloc(100 * sizeof(char)); 
        if (line[i] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

void initFile(char *file)
{
    fileread = readFromFile(file);
}

void freemem(char** line)
{
    for (int i = 0; i < 10; i++) {
        free(line[i]);
    }
}
