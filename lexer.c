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
                cont++;
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

    scan(lexme);
}
Word* analisetoken(char* token) {
    Word* word = get_value_by_key(table, STRING_TYPE, (char*)token);
    if (!word) {
        Word* nword = allocate_memory_for_word(ID, token);
        create_item(table, token, STRING_TYPE, nword, WORD_TYPE);
        return get_value_by_key(table, STRING_TYPE, (char*)token);
    }
    else {
        return word;
    }
}
Word** scan(char** lexme) {
    initTable();
    initkKeyWorld();
    Word** allToken = allocateMemoryForToken(cont);
    for (i32_t i = 0; i <= cont; i++)
    {
        char* prev = lexme[i];

        Word* word = analisetoken(prev);

        if (word) {
            allToken[i] = word;
        }
    }
    return allToken;
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
        line[i] = (char*)malloc(20 * sizeof(char));
        if (line[i] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}
void initTable() {
    table = allocate_memory_table(2);
}

void initkKeyWorld() {
    Word* createkey = allocate_memory_for_word(CREATE, "CREATE");
    Word* tablekey = allocate_memory_for_word(TABLE, "TABLE");
    Word* chartype = allocate_memory_for_word(VARCHAR, "VARCHAR");
    Word* openbracket = allocate_memory_for_word(OPPENNINGBRACKET, "(");
    Word* closebracket = allocate_memory_for_word(CLOSEBRACKET, ")");
    create_item(table, createkey->lexema, STRING_TYPE, createkey, WORD_TYPE);
    create_item(table, tablekey->lexema, STRING_TYPE, tablekey, WORD_TYPE);
    create_item(table, chartype->lexema, STRING_TYPE, chartype, WORD_TYPE);
    create_item(table, openbracket->lexema, STRING_TYPE, openbracket, WORD_TYPE);
    create_item(table, closebracket->lexema, STRING_TYPE, closebracket, WORD_TYPE);
}

Word* allocateMemoryForToken(i32_t size)
{
    Word* word = (Word*)malloc(sizeof(Word) * size);
    if (!word) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return word;
}
