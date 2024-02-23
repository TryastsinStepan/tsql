#pragma once

Item* allocate_memory_item(ptr key, DataType type_key, ptr value, DataType type_value);
void create_bucket(HashTable* hash_table, ptr key, DataType type_key, ptr value, DataType type_value);
void free_memory_table(HashTable* hash_table);
void free_memory_item(Item* item);
