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
    if (!list) {
        return;
    }
    free(list);
    return;
}
void free_memory_full_list(List* list) {
    if (!list) {
        return; 
    }
    List* next;
    while (list != NULL) {
        next = list->next;
        free(list);
        list = next;
        return;
    }
    free(list);
    return;
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
    while (temp->next != NULL) {
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
    List* current = list;
    while (current != NULL) {
        switch (current->data->key->type) {
        case INT_TYPE:
            printf("  Elem: " "key: %d, ", ((int)current->data->key->keyI));
            break;
        case STRING_TYPE:
            printf("  Elem: key: %s, ", (char*)current->data->key->keyI);
            break;
        case CHAR_TYPE:
            printf("  Elem: key: %c, ", ((char)current->data->key->keyI));
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
List* del(List* list, ItemMap* data) {
    if (!list) {
        printf("Error: list is NULL\n");
        return;
    }
    if (!data) {
        printf("Error: data is NULL\n");
        return;
    }
    List* current = list;
    if (current->data == data) {
        list = current->next;
        free_memory_list(current);
        return list;
    }
    while (current->next != NULL) {
        if (current->next->data == data) {
            List* curDel = current->next;
            current->next = curDel->next;
            free_memory_list(curDel);
        }
        else {
            current = current->next;
        }
    }
    return list;
}
int findoftype(DataType type, ptr firstkey, ptr secondkey) {
    switch (type) {
    case STRING_TYPE: {
        char* fkey = (char*)firstkey;
        char* skey = (char*)secondkey;
        if (strcmp(fkey, skey) == 0) {
            return 1;
        }
        break;
    }
    case INT_TYPE: {
        int fkey = (int)firstkey;
        int skey = (int)secondkey;
        if (fkey == skey) {
            return 1;
        }
        break;
    }
    case CHAR_TYPE: {
        char* fkey = (char*)firstkey;
        char* skey = (char*)secondkey;
        if (strcmp(fkey, skey) == 0) {
            return 1;
        }
        break;
    }
    case WORD_TYPE: {
        Word* fkey = (Word*)firstkey;
        Word* skey = (Word*)secondkey;
        if (fkey->id == skey->id && strcmp(fkey->lexema, skey->lexema) == 0) {
            return 1;
        }
        break;
    }
    }
    return 0;
}
ItemMap* find(List* list, DataType type, ptr key) {
    List* current = list;
    while (current != NULL) {
        if (findoftype(type, key, current->data->key->keyI)) {
            return current->data;
        }
        current = current->next;
    }
}