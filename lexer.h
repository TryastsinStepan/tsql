#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
char peek;
char prev;
#define WORD_LENGTH 20
int cont;
void lexer();
char** initLine();
void scan(char** lexme);
char** allocMemoryLexer();
void printLexme(char** lexme);