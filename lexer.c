 
#include"lexer.h"

void lexer() {
    char** line = initLine();
    char word[20];
    char** lexme= allocMemoryLexer();
    int c = 0;
    int g = 0;
    int f = 0;
    int n = 0;
    for (int i = 0; i < count; i++) {
        char ch;
        while ((ch = line[c][g]) != '\0') {
            if ((ch == ' ' || ch == '\n') && n > 0) {
                strcpy_s(lexme[c], 20, word);
                printf("%s", lexme[c]);
                f++;
                g++;
                memset(word, 0, sizeof(word));
                n = 0;
                continue;
            }
    
            if (n < sizeof(word) - 1) {
                word[n] = ch;
                word[n + 1] = '\0';
                n++;
            }
            else {
                printf("Error: Invalid size\n");
                return;
            }
            g++;
        }
        c++;
        g = 0;
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

