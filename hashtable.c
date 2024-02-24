#include "hashtable.h"

i32_t hash_function(ItemMap* item) {
	i32_t index = 0;
	if (!item) {
		printf("Error: Cant find this elem\n");
		free_memory_item(item);
		return NULL;
	}
	switch (item->key->type){
	case STRING_TYPE:
		index = hash_function_string(item->key->keyI, item->key->type, size_hash_table);
		break;
	case INT_TYPE:
		index = hash_function_int(item->key->keyI, item->key->type, size_hash_table);
		break;
	case CHAR_TYPE:
		index = hash_function_int(item->key->keyI, item->key->type, size_hash_table);
		break;
	}
	return index;
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
	size_hash_table = size;
	memory_table->count = 0;
	memory_table->items = (ItemMap**)calloc(size, sizeof(ItemMap*));
	if (!memory_table->items) {
		printf("Error: Failed to allocate memory for item\n");
		free(memory_table);
		return NULL;
	}
	for (i32_t i = 0; i < size_hash_table; i++) {
		memory_table->items[i] = NULL;
	}
	return memory_table;
}

ItemMap* allocate_memory_item(ptr key, DataType type_key, ptr value, DataType type_value) {
	ItemMap* item = (ItemMap*)malloc(sizeof(ItemMap));
	if (!item) {
		printf("Error: Failed to allocate memory for item\n");
		return NULL;
	}
	item->key = (ItemKey*)malloc(sizeof(ItemKey));
	if (!item->key) {
		printf("Error: Failed to allocate memory for item key\n");
		free(item);
		return NULL;
	}
	item->key->type = type_key;
	item->key->keyI = key;

	item->value = (ItemValue*)malloc(sizeof(ItemValue));
	if (!item->value) {
		printf("Error: Failed to allocate memory for item value\n");
		free(item);
		return NULL;
	}
	item->value->type = type_value;
	item->value->data = value;
	return item;
}

void create_bucket(HashTable* hash_table, ptr key, DataType type_key, ptr value,DataType type_value) {
	if (key == NULL || value == NULL) {
		printf("Error: Pass the actual parameters\n");
		return;
	}
	if (hash_table == NULL) {
		printf("Error: Such hashtable does not exist\n");
		return;
	}
	ItemMap* item = allocate_memory_item(key, type_key, value, type_value);
	i32_t index = hash_function(item);
	hash_table->items[index] = item;
	hash_table->count++;
	return;
}

void print_all_hash_table(HashTable* table) {
	if (!table) {
		printf("Error: can't print it\n");
		return;
	}
	printf("-----------My Hash Table-----------\n");
	if (table) {
		for (i32_t i = 0; i < size_hash_table; i++) {
			if (table->items[i] != NULL) {
				switch (table->items[i]->key->type) {
				case  INT_TYPE:
					printf_s("Elem:(index: %d key: %d ",i, ((int)(table->items[i]->key->keyI)));
					break;
				case  STRING_TYPE:
					printf_s("Elem:(index: %d key: %s ",i, ((char*)(table->items[i]->key->keyI)));
					break;
				case  CHAR_TYPE:
					printf_s("Elem:(index: %d key: %c ", i, ((char)(table->items[i]->key->keyI)));
					break;
				}

				switch (table->items[i]->value->type) {
				case STRING_TYPE:
					printf("value: %s )\n", ((char*)(table->items[i]->value->data)));
					break;
				case INT_TYPE:
					printf("value: %d )\n", ((int)(table->items[i]->value->data)));
					break;
				case CHAR_TYPE:
					printf("value: %c )\n", ((char)(table->items[i]->value->data)));
					break;
				}
			}
		}
	}
}

void free_memory_table(HashTable* memory) {
	if (!memory) {
		printf("Error: Failed to allocate memory for table\n");
		return;
	}
	if (memory) {
		for (int i = 0; i < size_hash_table; i++) {
			free_memory_item(memory->items[i]);
		}
		free(memory->items);
		free(memory);
	}
	printf("The memory has been successfully cleared\n");
	return;
}

void free_memory_item(ItemMap* item) {
	if (item) {
		free(item->key->keyI);
		free(item->key);
		free(item->value->data);
		free(item->value);
		free(item);
	}
}
