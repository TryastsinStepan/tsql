#pragma once
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct ItemList {
	struct ItemList* next;
	ptr data;
} ItemList;

typedef struct List {
	struct ItemList* head;
	i32_t count;
} List;

List* allocate_memory_list(int size);
ItemList* allocate_memory_item(ptr data);

void free_memory_list(List* list);
void free_memory_item(ItemList* item);

void push(List* list, ptr data);
void print_list(List* list);