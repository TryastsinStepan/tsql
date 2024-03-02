#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
char peek;
char prev;
void lexer();
char** initLine();
void readSym(char sym);
char** allocMemoryLexer();
