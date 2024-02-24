#include "list.h"

List* allocate_memory_list() {
    List* list = (List*)malloc(sizeof(List));
    if (!list) {
        printf("Error: Failed to allocate memory for list\n");
        exit(EXIT_FAILURE);
    }
    list->count = 0;
    list->head = NULL;
    return list;
}

ItemList* allocate_memory_item_list(ptr data) {
    if (!data) {
        printf("Error: Invalid data equals NULL\n");
        exit(EXIT_FAILURE);
    }
    ItemList* item = (ItemList*)malloc(sizeof(ItemList));
    if (!item) {
        printf("Error: Failed to allocate memory for item\n");
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
    free(list);
}

void free_memory_item(ItemList* item) {
    if (item) {
        free(item->data);
        free(item);
    }
}

void push(List* list, ptr data) {
    ItemList* item = allocate_memory_item_list(data);
    if (!item) {
        printf("Error: Failed to allocate memory for item\n");
        return;
    }

    if (list->head == NULL) {
        list->head = item;
    }
    else {
        ItemList* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = item;
    }
}

void print_list(List* list) {
    if (!list) {
        printf("Error: list is NULL\n");
        return;
    }
    printf("-----------My List-----------\n");
    ItemList* current = list->head;
    while (current != NULL) {
        printf("Elem: link: %p value: %s\n", current->next, current->data);
        current = current->next;
    }
}