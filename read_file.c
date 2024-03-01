#include "read_file.h"

char** readFromFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
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
        strcpy(lines[i], line);
        i++;
    }

    fclose(file);
    return lines;
}
