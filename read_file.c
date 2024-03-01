#include "read_file.h"

char** readFromFile(char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "r") != 0) {
        fprintf(stderr, "Can't open file %s\n", filename);
        exit(1);
    }

    char line[100];
    char** lines = (char**)malloc(1000 * sizeof(char*));
    if (lines == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL && i < 1000) {
        lines[i] = (char*)malloc(strlen(line) + 1);
        if (lines[i] == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }
        strcpy_s(lines[i], strlen(line) + 1, line);
        i++;
    }

    fclose(file);
    lines[i] = NULL;
    return lines;
}