#include <stdlib.h>   
#include <stdio.h>
#include <malloc.h>
#include "tofdata.h"
typedef struct HashTable {
	ptr key;
	ptr value;
}HashTable;
void hashfunction(ptr key);
HashTable* allocmemory(int size);
void createbuck(ptr key, ptr value);
void freemem(ptr memory);
int main(void)
{
	HashTable* hTable= allocmemory(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		exit(0);
	}
	//createbuck(1,"Hello", hTable);
	freemem(hTable);
	return 0;
}

void hashfunction(ptr key)
{

}

HashTable** addelem(ptr value)
{
	return NULL;
}

HashTable* allocmemory(int size)
{
	if (size < 0) {
		printf("Error: Invalid size for memory allocation (%d)\n", size);
		return NULL;
	}
	ptr memory = (HashTable*)malloc(sizeof(HashTable) * size);
	if (!memory) {
		printf("Error: Failed to allocate memory\n");
		return NULL;
	}
	return memory;
}

void createbuck(ptr key, ptr value)
{

	return ;
}

void freemem(ptr memory)
{
	free(memory);
	return;
}
