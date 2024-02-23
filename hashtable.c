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
		printf("Error: Failed to allocate memory for table\n");
		free_memory_table(memory_table);
		return NULL;
	}
	memory_table->size = size;
	memory_table->count = 0;
	memory_table->items = (Item**)calloc(size, sizeof(Item*));
	if (!memory_table->items) {
		printf("Error: Failed to allocate memory for item\n");
		free(memory_table);
		return NULL;
	}
	for (i32_t i = 0; i < memory_table->size; i++) {
		memory_table->items[i] = NULL;
	}
	return memory_table;
}

Item* allocate_memory_item(ptr key, ptr value, DataType type) {
	Item* item = (Item*)malloc(sizeof(Item));
	if (!item) {
		printf("Error: Failed to allocate memory for item\n");
		return NULL;
	}

	item->key = key;
	item->value = (ItemValue*)malloc(sizeof(ItemValue));
	if (!item->value) {
		printf("Error: Failed to allocate memory for item value\n");
		free(item);
		return NULL;
	}
	item->value->type = type;
	item->value->data = value;
	return item;
}

void create_bucket(HashTable* hash_table, ptr key, ptr value,DataType type) {
	if (key == NULL || value == NULL) {
		printf("Error: Pass the actual parameters\n");
		return;
	}
	if (hash_table == NULL) {
		printf("Error: Such hashtable does not exist\n");
		return;
	}
	i32_t index = hash_function(key);
	Item* item = allocate_memory_item(key, value, type);
	hash_table->items[index] = item;
	hash_table->count++;
	return;
}

void print_hash_table(HashTable* table) {
	if (!table) {
		printf("Error: can't print it\n");
		return;
	}
	printf("-----------My Hash Table-----------\n");
	for (i32_t i = 0; i < table->size; i++) {
		if (table->items[i] != NULL) {
			printf("Elem:(key: %p value: %s)\n", table->items[i]->key, table->items[i]->value);
		}
	}
	printf("\t  -------------------\n\n");
}

void free_memory_table(HashTable* memory) {
	if (!memory) {
		printf("Error: Failed to allocate memory for table\n");
		return;
	}
	for (i32_t i = 0; i < memory->size; i++) {
		Item* item = memory->items[i];
		free_memory_item(item);
	}
	free(memory->items);
	free(memory);
	printf("The memory has been successfully cleared\n");
	return;
}

void free_memory_item(Item* item) {
	free(item->key);
	free(item->value);
	free(item);
}
