#pragma once
#include "utils.h"
#include "strucrt.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct List {
	ItemMap* data;
	struct List* next;
	i32_t count;
} List;

List* allocate_memory_list();


void free_memory_list(List* list);

List* push(List* list, ItemMap* data);
void print_list(List* list);
