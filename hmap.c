#include"hmap.h"
HashTable* allocate_memory_table(int size) {
	if (size <= 0) {
		printf("Error: Invalid size for memory allocation (%d)\n", size);
		return NULL;
	}

	HashTable* memory_table = (HashTable*)malloc(sizeof(HashTable));
	if (!memory_table) {
		printf("Error: Failed to allocate memory for table\n");
		return NULL;
	}
	size_hash_table = size;
	memory_table->count = 0;

	memory_table->items = (ItemMap**)calloc(size, sizeof(ItemMap*));
	if (!memory_table->items) {
		printf("Error: Failed to allocate memory for item array\n");
		free(memory_table);
		return NULL;
	}

	for (i32_t i = 0; i < size_hash_table; i++) {
		memory_table->items[i] = NULL;
	}
	memory_table->buckets = create_buckets();
	if (!memory_table->buckets) {
		printf("Error: Failed to create buckets\n");
		free_memory_item(memory_table->items);
		free_memory_table(memory_table); // освободим память, выделенную для таблицы
		return NULL;
	}
	return memory_table;
}
void print_all_hash_table(HashTable* table) {
	if (!table) {
		printf("Error: Hash table is NULL\n");
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
		printf("Error: Failed to allocate memory for table\n");
		return;
	}
	ItemMap* item = get_item_by_key(hash_table, type, key);
	if (item != NULL) {
		switch (item->key->type) {
		case  INT_TYPE:
			printf_s("Elem:( key: %d ", ((int)(item->key->keyI)));
			break;
		case  STRING_TYPE:
			printf_s("Elem:( key: %s ", ((char*)(item->key->keyI)));
			break;
		case  CHAR_TYPE:
			printf_s("Elem:( key: %c ", ((char)(item->key->keyI)));
			break;
		default:
			printf_s("No such key exists");
			break;
		}

		switch (item->value->type) {
		case STRING_TYPE:
			printf("value: %s )\n", ((char*)(item->value->data)));
			break;
		case INT_TYPE:
			printf("value: %d )\n", ((int)(item->value->data)));
			break;
		case CHAR_TYPE:
			printf("value: %c )\n", ((char)(item->value->data)));
			break;
		default:
			printf_s("No such type exists");
			break;
		}
	}
	else {
		printf_s("No such item exists\n");
	}

}
void create_item(HashTable* hash_table, ptr key, DataType type_key, ptr value, DataType type_value) {
	if (key == NULL || value == NULL) {
		printf("Error: Pass the actual parameters\n");
		return;
	}
	if (hash_table == NULL) {
		printf("Error: Such hashtable does not exist\n");
		return;
	}
	ItemMap* item = allocate_memory_item_table(key, type_key, value, type_value);
	i32_t index = hash_function(key, type_key);
	ItemMap* currentItem = hash_table->items[index];
	if (currentItem == NULL) {
		if (hash_table->count == size_hash_table) {
			printf("Error: Hash Table is full\n");
			free_memory_item(currentItem);
			return;
		}
		hash_table->items[index] = item;
		hash_table->count++;
	}
	else {
		handle_collision(hash_table, index, item);
		return;
	}
	return;
}
ptr get_value_by_key(HashTable* hash_table, DataType type, ptr key) {
	if (!hash_table) {
		fprintf(stderr, "Error: Hash table is NULL\n");
		return NULL;
	}

	i32_t index = hash_function(key, type);
	ItemMap* sItem = hash_table->items[index];
	List* findl = hash_table->buckets[index];
	if (sItem != NULL) {
		if (hash_table->items[index]->key->keyI == key) {
			return sItem->value->data;
		}
		ItemMap* foundItem = find(findl, type, key);
		if (foundItem != NULL) {
			return foundItem->value->data;
		}
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
		free_memory_list(memory->buckets[i]);
	}
	free(memory->buckets);

	free(memory);
	printf("Memory has been successfully cleared\n");
}
void delete_elem(HashTable* hash_table, ptr key, DataType type_key) {
	if (!hash_table) {
		fprintf(stderr, "Error: Hash table is NULL\n");
		return NULL;
	}
	i32_t index = hash_function(key, type_key);
	ItemMap* sItem = hash_table->items[index];
	List* l = hash_table->buckets[index];
	if (sItem != NULL) {
		if (hash_table->items[index]->key->keyI == key) {
			free_memory_item(hash_table->items[index]);
			hash_table->items[index] = NULL;
			printf("Elem was delete\n");
		}
		if (l->data->key->keyI == key) {
			ItemMap* delet = l->data;
			del(l, delet);
			hash_table->buckets[index] = NULL;
			printf("Elem was delete\n");
		}

	}
	balance_table(hash_table);
}