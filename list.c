#include "list.h"

List* allocate_memory_list() {
	List* list = (List*)malloc(sizeof(List*));
	if (!list) {
		printf("Error: Failed to allocate memory for list\n");
		free_memory_list(list);
		exit(EXIT_FAILURE);
	}
	list->count = 0;
	list->head = NULL;
	return list;
}

ItemList* allocate_memory_item(ptr data) {
	if (data == NULL) {
		printf("Error: Invalid data equals NULL\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	ItemList* item = (ItemList*)malloc(sizeof(ItemList*));
	if (!item) {
		printf("Error: Failed to allocate memory for list\n");
		free_memory_list(item);
		exit(EXIT_FAILURE);
	}
	item->data = data;
	item->next = NULL;
	return item;
}

void free_memory_list(List* list) {
	if (!list) {
		printf("Error: Failed to allocate memory for table\n");
		return;
	}

	ItemList* current = list->head;
	ItemList* next;
	while (current) {
		next = current->next;
		free_memory_item(current);
		current = next;
	}
}

void free_memory_item(ItemList* item) {
	if (item) {
		free_memory_item(item->next); 
		free(item->data); 
		free(item); 
	}
}

void push(List* list, ptr data) {

}

void print_list(List* list) {

}