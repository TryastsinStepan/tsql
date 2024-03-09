#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"IDTAG.h"
#include "hmap.h"
#include "parser.h"
#define WORD_LENGTH 20
HashTable* table;
int cont;
void lexer();
char** initLine();
Word** scan(char** lexme);
char** allocMemoryLexer();
void initTable();
void put(Word* word);
void initkKeyWorld();
void findKeyWorld();
Word* allocateMemoryForToken(i32_t size);
