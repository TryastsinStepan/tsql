#include <stdlib.h>   
#include <stdio.h>
#include <malloc.h>

typedef struct HashTable {
	void* key;
	void* value;
}HashTable;
void hashfunction(void* key);
HashTable** addelem(void* value);
HashTable** allocmemory(int size);
HashTable* createbuck(void* key,void* value);
void freemem(void* memory);
int main(void)
{
	HashTable** hTable= allocmemory(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		return 1; 
	}
	hTable[0] = createbuck();
	freemem(hTable);
	return 0;
}

void hashfunction(void* key)
{

}

HashTable** addelem(void* value)
{
	return NULL;
}

HashTable** allocmemory(int size)
{
	if (size < 0) {
		printf("Error: Invalid size for memory allocation (%d)\n", size);
		return NULL;
	}
	void** memory = (HashTable**)malloc(sizeof(HashTable) * size);
	if (!memory) {
		printf("Error: Failed to allocate memory\n");
		return NULL;
	}
	return memory;
}

HashTable* createbuck(void* key, void* value)
{
	return nullptr;
}

void freemem(void* memory)
{
	free(memory);
	return;
}
