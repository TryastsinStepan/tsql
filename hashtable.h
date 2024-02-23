
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"
#include "datatypes.h"

typedef struct ItemValue {
    DataType type;
    ptr data;
} ItemValue;

typedef struct Item {
    ptr key;
    ItemValue* value;
} Item;

typedef struct HashTable {
    Item** items;  
    i32_t size;
    i32_t count;
} HashTable;

i32_t hash_function(ptr key); 
HashTable* allocate_memory_table(int size);  
Item* allocate_memory_item(ptr key, ptr value, DataType type);
void create_bucket(HashTable* hash_table,ptr key, ptr value,DataType type);
void free_memory_table(HashTable* hash_table); 
void free_memory_item(Item* item);  
void print_hash_table(HashTable* hash_table);  