
#include <stdlib.h>   
#include <stdio.h>
#include <malloc.h>
#include < string.h>
#include  "utils.h"
typedef struct Item {
	ptr key;
	ptr value;
}Item;

typedef struct HashTable {
	Item** item;
	i32_t size;
	i32_t count;

}HashTable;

i32_t hashfunction(ptr key);
HashTable* allocmemorytable(int size);
Item* allocmemoryitem(ptr key, ptr value);
void createbuck(ptr key, ptr value, HashTable* hTable);
void freememtable(HashTable* memory);
void freememitem(Item* item);
void printhashtable(HashTable* table);
