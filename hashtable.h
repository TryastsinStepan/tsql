#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"
#include "hashfunction.h"
i32_t size_hash_table;

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
} ItemMap;

typedef struct HashTable {
    ItemMap** items;
    i32_t count;
} HashTable;



HashTable* allocate_memory_table(int size);  
static ItemMap* allocate_memory_item(ptr key, DataType type_key, ptr value, DataType type_value);


void create_bucket(HashTable* hash_table, ptr key, DataType type_key, ptr value, DataType type_value);


static void free_memory_item(ItemMap* item);
void free_memory_table(HashTable* hash_table);


i32_t hash_function(ptr key, DataType type_key);
ItemMap* get_item_by_key(HashTable* hash_table, DataType type, ptr key);
ptr get_value_by_key(HashTable* hash_table, DataType type, ptr key);

void print_all_hash_table(HashTable* hash_table);
void print_elem_by_key(HashTable* hash_table, DataType type, ptr key);