#include <stdlib.h>   
#include <stdio.h>
#include <malloc.h>
#include "tofdata.h"
typedef struct Item {
	ptr key;
	ptr value;
}Item;

typedef struct HashTable {
	Item** item;
	i32_t size;

}HashTable;

ptr hashfunction(ptr key);
HashTable* allocmemory(int size);
void createbuck(ptr key, ptr value, HashTable* hTable);
void freememtable(HashTable* memory);
void freememitem(Item* item);
int main(void)
{
	HashTable* hTable= allocmemory(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		freemem(hTable);
		exit(0);
	}
	//createbuck(1,"Hello", hTable);
	freemem(hTable);
	return 0;
}

ptr hashfunction(ptr key)
{
   
}

HashTable* allocmemory(int size)
{
	if (size < 0) {
		printf("Error: Invalid size for memory allocation (%d)\n", size);
		return NULL;
	}
	HashTable* memory_table = (HashTable*)malloc(sizeof(HashTable));
	if (!memory_table) {
		printf("Error: Failed to allocate memory\n");
		freemem(memory_table);
		return NULL;
	}
	memory_table->size = size;
	memory_table->item = (Item**)calloc(size,sizeof(Item));
	if (!memory_table->item) {
		printf("Error: Failed to allocate memory\n");
		freemem(memory_table);
		return NULL;
	}
	for (i32_t i = 0; i < memory_table->size; i++)
	{
		memory_table->item[i] = NULL;
	}
	return memory_table;
}

void createbuck(ptr key, ptr value, HashTable* hTable)
{
	if (key == NULL || value == NULL) {
		printf("Error: Pass the actual parameters \n");
		return NULL;
	}
	if (hTable == NULL) {
		printf("Error: Such hashtable does not exist \n");
		return NULL;
	}
	hTable->item[0]->key = hashfunction(key);
	hTable->item[0]->value = value;
	return;
}

void freememtable(HashTable* memory)
{
	if (!memory) {
		printf("Error: Failed to allocate memory\n");
		return NULL;
	}
	for (i32_t i = 0; i < memory->size; i++)
	{
		Item* item = memory->item[0];
		freememitem(item);
	}
	free(memory->item);
	free(memory);
	return;
}

void freememitem(Item* item)
{
	free(item->key);
	free(item->value);
	free(item);
}
