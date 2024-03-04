#include "word.h"

Word* allocate_memory_for_word(i32_t id,char* word)
{
	if (!word) {
		printf("Error: Invalid word\n");
		return;
	}
	Word* rword = (Word*)malloc(sizeof(Word));
	if (!rword) {
		printf("Error: Failed to allocate memory for word\n");
		return;
	}
	rword->lexema = word;
	rword->id = id;
	return rword;
}

void free_memory_for_word(Word* mem)
{
	if (!mem) {
		printf("Error: Invalid memory\n");
		return;
	}
	free(mem->lexema);
	free(mem);
}
