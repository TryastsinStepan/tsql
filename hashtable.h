#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"
#include "datatypes.h"
#include "hashfunction.h"
typedef struct ItemValue {
    DataType type;
    ptr data;
} ItemValue;

typedef struct ItemKey {
    DataType type;
    ptr keyI;
} ItemKey;

typedef struct Item {
    ItemKey* key;
    ItemValue* value;
} Item;

typedef struct HashTable {
    Item** items;  
    i32_t size;
    i32_t count;
} HashTable;

i32_t hash_function(Item* item); 
void print_all_hash_table(HashTable* hash_table);
HashTable* allocate_memory_table(int size);  
void free_memory_table(HashTable* hash_table);
void create_bucket(HashTable* hash_table, ptr key, DataType type_key, ptr value, DataType type_value);

static Item* allocate_memory_item(ptr key, DataType type_key, ptr value, DataType type_value);
static void free_memory_item(Item* item);

