#include "hashtable.h"
i32_t hash_function(ptr key) {
	return 1;
}

HashTable* allocate_memory_table(int size) {
	if (size < 0) {
		printf("Error: Invalid size for memory allocation (%d)\n", size);
		return NULL;
	}
	HashTable* memory_table = (HashTable*)malloc(sizeof(HashTable));
	if (!memory_table) {
		printf("Error: Failed to allocate memory\n");
		freememtable(memory_table);
		return NULL;
	}
	memory_table->size = size;
	memory_table->count = 0;
	memory_table->items = (Item**)calloc(size, sizeof(Item*));
	if (!memory_table->items) {
		printf("Error: Failed to allocate memory\n");
		free(memory_table);
		return NULL;
	}
	for (i32_t i = 0; i < memory_table->size; i++) {
		memory_table->items[i] = NULL;
	}
	return memory_table;
}

Item* allocate_memory_item(ptr key, ptr value) {
	Item* item = (Item*)malloc(sizeof(Item));
	if (!item) {
		printf("Error: Failed to allocate memory\n");
		return NULL;
	}
	item->key = (ptr*)malloc(sizeof(key));
	item->value = (ptr*)malloc(sizeof(value));
	if (!item->key || !item->value) {
		printf("Error: Failed to allocate memory\n");
		freememitem(item);
		return NULL;
	}
	item->key = key;
	item->value = value;
	return item;
}

void create_bucket(ptr key, ptr value, HashTable* hTable) {
	if (key == NULL || value == NULL) {
		printf("Error: Pass the actual parameters\n");
		return;
	}
	if (hTable == NULL) {
		printf("Error: Such hashtable does not exist\n");
		return;
	}
	i32_t index = hashfunction(key);
	Item* item = allocmemoryitem(key, value);
	hTable->items[index] = item;
	hTable->count++;
	return;
}

void free_memory_table(HashTable* memory) {
	if (!memory) {
		printf("Error: Failed to allocate memory\n");
		return;
	}
	for (i32_t i = 0; i < memory->size; i++) {
		Item* item = memory->items[i];
		freememitem(item);
	}
	free(memory->items);
	free(memory);
	return;
}

void free_memory_item(Item* item) {
	free(item->key);
	free(item->value);
	free(item);
}

void print_hash_table(HashTable* table) {
	if (!table) {
		printf("Error: can't print it\n");
		return;
	}
	printf("-----------My Hash Table-----------\n");
	for (i32_t i = 0; i < table->size; i++) {
		if (table->items[i] != NULL) {
			printf("Elem:(key: %p value: %p)\n", table->items[i]->key, table->items[i]->value);
		}
	}
	printf("\t  -------------------\n\n");
}