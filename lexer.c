#define _CRT_SECURE_NO_WARNINGS
#include"lexer.h"
void lexer() {
    char** line = initLine();
    char word[20];
    char** lexme = allocMemoryLexer();
    int wordIndex = 0; 
    int lexmeIndex = 0;
    for (int lineIndex = 0; lineIndex < count; lineIndex++) {
        for (int charIndex = 0; line[lineIndex][charIndex] != '\0'; charIndex++) {
            char ch = line[lineIndex][charIndex];
            if ((ch == ' ' || ch == '\n') && wordIndex > 0) {
                word[wordIndex] = '\0'; 
                strcpy_s(lexme[lexmeIndex++], 20, word);
                wordIndex = 0; 
            }
            else if (wordIndex < sizeof(word) - 1) {
                word[wordIndex++] = ch; 
            }
            else {
                printf("Error: Invalid size\n");
                return;
            }
        }
    }
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        strcpy_s(lexme[lexmeIndex++], 20, word);
    }

    printLexme(lexme);
}
void printLexme(char** lexme) {
    for (i32_t i = 0; i < 6; i++)
    {
        printf("%s ", lexme[i]);
    }
}
char** initLine()
{
    initFile("file.txt");
    return parseLineByLine();
}
char** allocMemoryLexer() {
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
