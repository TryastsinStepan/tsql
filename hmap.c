﻿#include"hmap.h"
HashTable* allocate_memory_table(int size) {
	if (size <= 0) {
		fprintf(stderr, "Error: Invalid size for memory allocation (%d)\n", size);
		return NULL;
	}

	HashTable* memory_table = (HashTable*)malloc(sizeof(HashTable));
	if (!memory_table) {
		fprintf(stderr, "Error: Failed to allocate memory for table\n");
		return NULL;
	}

	size_hash_table = size;
	memory_table->count = 0;

	memory_table->items = (ItemMap**)calloc(size, sizeof(ItemMap*));
	if (!memory_table->items) {
		fprintf(stderr, "Error: Failed to allocate memory for item array\n");
		free(memory_table);
		return NULL;
	}

	for (i32_t i = 0; i < size_hash_table; i++) {
		memory_table->items[i] = NULL;
	}

	memory_table->buckets = create_buckets();
	if (!memory_table->buckets) {
		fprintf(stderr, "Error: Failed to create buckets\n");
		free_memory_item(memory_table->items);
		free_memory_table(memory_table);
		return NULL;
	}

	return memory_table;
}
void print_all_hash_table(HashTable* table) {
	if (!table) {
		fprintf(stderr, "Error: Hash table is NULL\n");
		return;
	}
	printf("-----------My Hash Table-----------\n");
	for (i32_t i = 0; i < size_hash_table; i++) {
		ItemMap* item = table->items[i];
		if (item != NULL) {
			switch (item->key->type) {
			case INT_TYPE:
				printf("Elem: index: %d, key: %d, ", i, ((int)(item->key->keyI)));
				break;
			case STRING_TYPE:
				printf("Elem: index: %d, key: %s, ", i, (char*)(item->key->keyI));
				break;
			case CHAR_TYPE:
				printf("Elem: index: %d, key: %c, ", i, ((char)(item->key->keyI)));
				break;
			case WORD_TYPE: {
				Word* word_ptr = (Word*)(item->key->keyI); 
				printf("Elem: index: %d, key: %p, ", i, word_ptr);
				break;
			}
			default:
				printf("No such key exists");
				break;
			}
			switch (item->value->type) {
			case STRING_TYPE:
				printf("value: %s\n", (char*)(item->value->data));
				break;
			case INT_TYPE:
				printf("value: %d\n", ((int)(item->value->data)));
				break;
			case CHAR_TYPE:
printf("value: %c\n", ((char)(item->value->data)));
break;
			case WORD_TYPE: {
				Word* word_ptr = (Word*)(item->value->data);
				printf("value: Word(%d ,%s) )\n", (int)word_ptr->id, (char*)word_ptr->lexema);
				break;
			}
			default:
				printf("No such value exists");
				break;
			}
		}
		List* bucket = table->buckets[i];
		if (bucket != NULL) {
			printf("Index bucket %d\nList\n", i);
			print_list(bucket);
		}
	}
}
void print_elem_by_key(HashTable* hash_table, DataType type, ptr key) {
	if (!hash_table) {
		fprintf(stderr, "Error: Hash table is NULL\n");
		return;
	}
	Word* word_ptr;
	ItemMap* item = get_item_by_key(hash_table, type, key);
	if (item != NULL) {
		switch (item->key->type) {
		case INT_TYPE:
			printf("Elem: key: %d, ", ((int)(item->key->keyI)));
			break;
		case STRING_TYPE:
			printf("Elem: key: %s, ", (char*)(item->key->keyI));
			break;
		case CHAR_TYPE:
			printf("Elem: key: %c, ", ((char)(item->key->keyI)));
			break;
		case WORD_TYPE: {
			printf("Elem: key: %p, ", ((Word*)(item->key->keyI)));
			break;
		}
		default:
			printf("No such key exists");
			break;
		}
		switch (item->value->type) {
		case STRING_TYPE:
			printf("value: %s\n", (char*)(item->value->data));
			break;
		case INT_TYPE:
			printf("value: %d\n", ((int)(item->value->data)));
			break;
		case CHAR_TYPE:
			printf("value: %c\n", ((char)(item->value->data)));
			break;
		case WORD_TYPE: {
			Word* word_ptr = (Word*)(item->value->data);
			printf("value: Word(%d ,%s) )\n", (int)word_ptr->id, (char*)word_ptr->lexema);
			break;
		}
		default:
			printf("No such value exists");
			break;
		}
	}
	else {
		printf_s("No such item exists\n");
	}

}
void create_item(HashTable* hash_table, ptr key, DataType type_key, ptr value, DataType type_value) {
	if (!hash_table) {
		fprintf(stderr, "Error: Hash table is NULL\n");
		return;
	}
	if (key == NULL || value == NULL) {
		fprintf(stderr, "Error: Pass the actual parameters\n");
		return;
	}

	i32_t index = hash_function(key, type_key);
	ItemMap* item = allocate_memory_item_table(key, type_key, value, type_value);
	if (item == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory for item\n");
		return;
	}

	ItemMap* currentItem = hash_table->items[index];
	if (currentItem == NULL) {
		if (hash_table->count == size_hash_table) {
			fprintf(stderr, "Error: Hash Table is full\n");
			free_memory_item(currentItem);
			return;
		}
		hash_table->items[index] = item;
		hash_table->count++;
	}
	else {
		handle_collision(hash_table, index, item);
	}
}
int castinandfind(DataType type, ptr firstkey, ptr secondkey) {
switch (type) {
	case STRING_TYPE: {
		char* fkey = (char*)firstkey;
		char* skey = (char*)secondkey;
		if (strcmp(fkey, skey) == 0) {
			return 1;
		}
		break;
	}
	case INT_TYPE: {
		int fkey = (int)firstkey;
		int skey = (int)secondkey;
		if (fkey == skey) {
			return 1;
		}
		break;
	}
	case CHAR_TYPE: {
		char* fkey = (char*)firstkey;
		char* skey = (char*)secondkey;
		if (strcmp(fkey, skey) == 0) {
			return 1;
		}
		break;
	}
	case WORD_TYPE: {
		Word* fkey = (Word*)firstkey;
		Word* skey = (Word*)secondkey;
		if (fkey->id == skey->id && strcmp(fkey->lexema, skey->lexema) == 0) {
			return 1;
		}
		break;
	}
}
return 0;
}
ptr get_value_by_key(HashTable* hash_table, DataType type, ptr key) {
	if (!hash_table) {
		fprintf(stderr, "Error: Hash table is NULL\n");
		return NULL;
	}

	i32_t index = hash_function(key, type);
	ItemMap* findInTableItem = hash_table->items[index];
	if (findInTableItem != NULL && castinandfind(type, key, findInTableItem->key->keyI)) {
		return findInTableItem->value->data;
	}

	ItemMap* findItemInBucketItem = find(hash_table->buckets[index], type, key);
	if (findItemInBucketItem != NULL && castinandfind(type, key, findItemInBucketItem->key->keyI)) {
		return findItemInBucketItem->value->data;
	}

	return NULL;
}
void free_memory_table(HashTable* memory) {
	if (!memory) {
		printf("Error: Hash table is NULL\n");
		return;
	}

	for (int i = 0; i < size_hash_table; i++) {
		free_memory_item(memory->items[i]);
	}
	free(memory->items);

	for (int i = 0; i < size_hash_table; i++) {
		free_memory_full_list(memory->buckets[i]);
	}
	free(memory->buckets);

	free(memory);
	printf("Memory has been successfully cleared\n");
}
void delete_elem(HashTable* hash_table, ptr key, DataType type_key) {
	if (!hash_table) {
		fprintf(stderr, "Error: Hash table is NULL\n");
		return;
	}

	i32_t index = hash_function(key, type_key);
	int flag = 0;
	ItemMap* sItem = hash_table->items[index];
	List* l = hash_table->buckets[index];

	if (sItem != NULL && castinandfind(type_key, key, sItem->key->keyI)) {
		free_memory_item(hash_table->items[index]);
		hash_table->items[index] = NULL;
		flag = 1;
		printf("Elem was deleted\n");
	}

	if (l != NULL && castinandfind(type_key, key, l->data->key->keyI)) {
		ItemMap* delet = l->data;
		List* save = del(l, delet);
		hash_table->buckets[index] = NULL;
		hash_table->buckets[index] = save;
		flag = 1;
		printf("Elem was deleted\n");
	}

	if (flag) {
		balance_table(hash_table);
	}

	if (!flag) {
		printf("Elem was not found\n");
	}
}