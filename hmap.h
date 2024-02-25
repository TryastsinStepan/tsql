#pragma once
#include "strucrt.h"
#include "utils.h"
#include"hashtable.h"
HashTable* allocate_memory_table(int size);
void print_all_hash_table(HashTable* hash_table);
void print_elem_by_key(HashTable* hash_table, DataType type, ptr key);
void create_item(HashTable* hash_table, ptr key, DataType type_key, ptr value, DataType type_value);
ptr get_value_by_key(HashTable* hash_table, DataType type, ptr key);
void free_memory_table(HashTable* hash_table);



