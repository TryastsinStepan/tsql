#include "hashtable.h"

i32_t hash_function(ptr key, DataType type_key ) {
	i32_t index = 0;
	switch (type_key){
	case STRING_TYPE:
		index = hash_function_string(key,size_hash_table);
		break;
	case INT_TYPE:
		index = hash_function_int(key, size_hash_table);
		break;
	case CHAR_TYPE:
		index = hash_function_char(key, size_hash_table);
		break;
	}
	return index;
}

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

List** create_buckets() {
	List** list = (List**)calloc(size_hash_table,sizeof(List*));
	if (!list) {
		printf("Error: Failed to allocate memory for buckets\n");
		return NULL;
	}

	for (i32_t i = 0; i < size_hash_table; i++) {
		list[i] = NULL;
	}

	return list;
}
void handle_collision(HashTable* hash_table, i32_t index, ItemMap* item) {
	if (!hash_table) {
		printf("Error: Hash table is NULL\n");
		return;
	}
	if (index < 0 || index >= size_hash_table) {
		printf("Error: Invalid index (%d)\n", index);
		return;
	}
	if (!item) {
		printf("Error: Item is NULL\n");
		return;
	}

	if (!hash_table->buckets) {
		printf("Error: Buckets array is NULL\n");
		return;
	}
	List* l = hash_table->buckets[index];
	if (l == NULL) {
		l = allocate_memory_list();
		l->data = item;
		l->next = NULL;
		hash_table->buckets[index] = l;
	}
	else {
		hash_table->buckets[index] = push(l, item);
	}
}
ItemMap* allocate_memory_item_table(ptr key, DataType type_key, ptr value, DataType type_value) {
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

void create_item(HashTable* hash_table, ptr key, DataType type_key, ptr value,DataType type_value) {
	if (key == NULL || value == NULL) {
		printf("Error: Pass the actual parameters\n");
		return;
	}
	if (hash_table == NULL) {
		printf("Error: Such hashtable does not exist\n");
		return;
	}
	ItemMap* item = allocate_memory_item_table(key, type_key, value, type_value);
	i32_t index = hash_function(key,type_key);
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
		handle_collision(hash_table,index, item);
		return;
	}
	return;
}

ItemMap* get_item_by_key(HashTable* hash_table, DataType type, ptr key) {
	if (!hash_table) {
		printf("Error: Failed to allocate memory for table\n");
		return NULL;
	}
	i32_t index = hash_function(key,type);
	ItemMap* sItem = hash_table->items[index];
	if(sItem!=NULL){
		if (hash_table->items[index]->key->keyI == key) {
			return sItem;
		}
	}
	return NULL;
}
ptr get_value_by_key(HashTable* hash_table, DataType type, ptr key) {
	if (!hash_table) {
		printf("Error: Failed to allocate memory for table\n");
		return NULL;
	}
	i32_t index = hash_function(key, type);
	ItemMap* sItem = hash_table->items[index];
	if (sItem != NULL) {
		if (hash_table->items[index]->key->keyI == key) {
			return sItem->value->data;
		}
	}
	return NULL;
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
			printf("Index bucket %d\nList\n",i);
			print_list(bucket);
		}
	}
}
void print_elem_by_key(HashTable* hash_table, DataType type,ptr key) {
	if (!hash_table) {
		printf("Error: Failed to allocate memory for table\n");
		return;
	}
	ItemMap* item = get_item_by_key(hash_table, type, key);
	if (item != NULL) {
		switch (item->key->type) {
		case  INT_TYPE:
				printf_s("Elem:( key: %d ",  ((int)(item->key->keyI)));
				break;
		case  STRING_TYPE:
				printf_s("Elem:( key: %s ",  ((char*)(item->key->keyI)));
				break;
		case  CHAR_TYPE:
				printf_s("Elem:( key: %c ",  ((char)(item->key->keyI)));
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
			printf_s("No such value exists");
			break;
		}
	}
	else {
		printf_s("No such item exists");
	}
	
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

void free_memory_item(ItemMap* item) {
	if (!item) {
		return;
	}
	free(item->key);
	free(item->value);
	free(item);
}