#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"
#include "hashfunction.h"
#include "list.h"

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
    List** buckets;
    i32_t count;
} HashTable;

HashTable* allocate_memory_table(int size);
ItemMap* allocate_memory_item_table(ptr key, DataType type_key, ptr value, DataType type_value);

List** create_buckets();
collision_handling(hash_table, index, item);
void handle_collision(HashTable* hash_table,i32_t index, ItemMap* item);

void create_item(HashTable* hash_table, ptr key, DataType type_key, ptr value, DataType type_value);

static void free_memory_item(ItemMap* item);
void free_memory_table(HashTable* hash_table);


i32_t hash_function(ptr key, DataType type_key);
ItemMap* get_item_by_key(HashTable* hash_table, DataType type, ptr key);
ptr get_value_by_key(HashTable* hash_table, DataType type, ptr key);

void print_all_hash_table(HashTable* hash_table);
void print_elem_by_key(HashTable* hash_table, DataType type, ptr key);