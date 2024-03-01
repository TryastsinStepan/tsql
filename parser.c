#include "parser.h"

char** parseLineByLine()
{
    char** lines = fileread;
    int i = 0;
    int c = 0;
    char** line = allocMemory();
    while (lines[i] != NULL && i < 100) {
        char* str = lines[i];
        int j = 0;
        while (*str != '\0') {
            if (*str != ' ') {
                line[c][j] = *str;
                j++;
            }
            else {
                line[c][j] = '\0';
                c++;
                j = 0;
            }
            str++;
        }
        line[c][j] = '\0';
        c++;
        i++;
    }
    return line;
}

char** allocMemory() {
    char** line = (char**)malloc(10 * sizeof(char*)); 
    if (line == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 10; i++) {
        line[i] = (char*)malloc(10 * sizeof(char)); 
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
