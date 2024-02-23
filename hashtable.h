
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "utils.h"

typedef struct Item {
    ptr key;
    ptr value;
} Item;

typedef struct HashTable {
    Item** items;  // Изменено на более информативное имя переменной
    i32_t size;
    i32_t count;
} HashTable;

i32_t hash_function(ptr key); 
HashTable* allocate_memory_table(int size);  
Item* allocate_memory_item(ptr key, ptr value);  
void create_bucket(ptr key, ptr value, HashTable* hash_table); 
void free_memory_table(HashTable* hash_table); 
void free_memory_item(Item* item);  
void print_hash_table(HashTable* hash_table);  