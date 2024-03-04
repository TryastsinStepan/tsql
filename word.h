#pragma once
#include"utils.h"
#include"token.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
typedef struct Word {
	int id;
	char* lexema;
	
}Word;
Word* allocate_memory_for_word(i32_t id,char* word);
void free_memory_for_word(Word* mem);
