#include "list.h"

List* allocate_memory_list() {
    List* list = (List*)malloc(sizeof(List));
    if (!list) {
        printf("Error: Failed to allocate memory for list\n");
        exit(EXIT_FAILURE);
    }
    list->count = 0;
    list->next = NULL;
  
    return list;
}

void free_memory_list(List* list) {
 

}

List* push(List* list, ItemMap* data) {
    if (!list) {
        List* head = allocate_memory_list();
        head->data = data;
        list = head;
        return list;
    }
    else if (list->next == NULL) {
        List* node = allocate_memory_list();
        node->data = data;
        node->next = NULL;
        list->next = node;
        return;
    }

    List* temp = list;
    while (temp->next!=NULL) {
        temp = temp->next;
    }

    List* node = allocate_memory_list();
    node->data = data;
    node->next = NULL;
    temp->next = node;
    return list;
}

void print_list(List* list) {
    if (!list) {
        printf("Error: list is NULL\n");
        return;
    }
    printf("-----------My List-----------\n");
    List* current = list;
    while (current != NULL) {
        printf("Elem: ");
        switch (current->data->key->type) {
        case INT_TYPE:
            printf("key: %d, ", ((int)current->data->key->keyI));
            break;
        case STRING_TYPE:
            printf("key: %s, ", (char*)current->data->key->keyI);
            break;
        case CHAR_TYPE:
            printf("key: %c, ", ((char)current->data->key->keyI));
            break;
        default:
            printf("Unknown key data type, ");
            break;
        }
        switch (current->data->value->type) {
        case INT_TYPE:
            printf("value: %d\n", ((int)current->data->value->data));
            break;
        case STRING_TYPE:
            printf("value: %s\n", (char*)current->data->value->data);
            break;
        case CHAR_TYPE:
            printf("value: %c\n", ((char)current->data->value->data));
            break;
        default:
            printf("Unknown value data type\n");
            break;
        }
        current = current->next;
    }
}