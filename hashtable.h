#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "strucrt.h"
#include "utils.h"
#include "hashfunction.h"
#include "list.h"

i32_t size_hash_table;
typedef struct HashTable {
     ItemMap** items;
     List** buckets;
    i32_t count;
} HashTable;
List** create_buckets();
void handle_collision(HashTable* hash_table,i32_t index, ItemMap* item);
i32_t hash_function(ptr key, DataType type_key);
void free_memory_item(ItemMap* item);
ItemMap* get_item_by_key(HashTable* hash_table, DataType type, ptr key);
ItemMap* allocate_memory_item_table(ptr key, DataType type_key, ptr value, DataType type_value);
void balance_table(HashTable* hash_table);
