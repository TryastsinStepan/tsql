#include "hashtable.h"
#include "hashtable.h"
#include <stdio.h>

i32_t hash_function(ptr key, DataType type_key) {
    i32_t index = 0;
    switch (type_key) {
    case STRING_TYPE:
        index = hash_function_string(key, size_hash_table);
        break;
    case INT_TYPE:
        index = hash_function_int(key, size_hash_table);
        break;
    case CHAR_TYPE:
        index = hash_function_char(key, size_hash_table);
        break;
    case WORD_TYPE:
        index = hash_function_word(key, size_hash_table);
        break;
    default:
        fprintf(stderr, "Error: Unknown key data type\n");
        break;
    }
    return index;
}

List** create_buckets() {
    List** list = (List**)calloc(size_hash_table, sizeof(List*));
    if (!list) {
        fprintf(stderr, "Error: Failed to allocate memory for buckets\n");
        return NULL;
    }

    for (i32_t i = 0; i < size_hash_table; i++) {
        list[i] = NULL;
    }

    return list;
}

void handle_collision(HashTable* hash_table, i32_t index, ItemMap* item) {
    if (!hash_table) {
        fprintf(stderr, "Error: Hash table is NULL\n");
        return;
    }
    if (index < 0 || index >= size_hash_table) {
        fprintf(stderr, "Error: Invalid index (%d)\n", index);
        return;
    }
    if (!item) {
        fprintf(stderr, "Error: Item is NULL\n");
        return;
    }
    if (!hash_table->buckets) {
        fprintf(stderr, "Error: Buckets array is NULL\n");
        return;
    }
    List* l = hash_table->buckets[index];
    if (l == NULL) {
        l = allocate_memory_list();
        l->data = item;
        l->next = NULL;
        hash_table->buckets[index] = l;
    }
    else {
        hash_table->buckets[index] = push(l, item);
    }
}

ItemMap* allocate_memory_item_table(ptr key, DataType type_key, ptr value, DataType type_value) {
    ItemMap* item = (ItemMap*)malloc(sizeof(ItemMap));
    if (!item) {
        fprintf(stderr, "Error: Failed to allocate memory for item\n");
        return NULL;
    }
    item->key = (ItemKey*)malloc(sizeof(ItemKey));
    if (!item->key) {
        fprintf(stderr, "Error: Failed to allocate memory for item key\n");
        free(item);
        return NULL;
    }
    item->key->type = type_key;
    item->key->keyI = key;

    item->value = (ItemValue*)malloc(sizeof(ItemValue));
    if (!item->value) {
        fprintf(stderr, "Error: Failed to allocate memory for item value\n");
        free(item->key);
        free(item);
        return NULL;
    }
    item->value->type = type_value;
    item->value->data = value;
    return item;
}

ItemMap* get_item_by_key(HashTable* hash_table, DataType type, ptr key) {
    if (!hash_table) {
        fprintf(stderr, "Error: Hash table is NULL\n");
        return NULL;
    }
    i32_t index = hash_function(key, type);
    ItemMap* sItem = hash_table->items[index];
    List* findl = hash_table->buckets[index];
    if (sItem != NULL) {
        if (hash_table->items[index]->key->keyI == key) {
            return sItem;
        }
        ItemMap* foundItem = find(findl, type, key);
        if (foundItem != NULL) {
            return foundItem;
        }
    }
    return NULL;
}

void free_memory_item(ItemMap* item) {
    if (!item) {
        return;
    }
    free(item->key);
    free(item->value);
    free(item);
}

void balance_table(HashTable* hash_table) {
    if (!hash_table) {
        fprintf(stderr, "Error: Hash table is NULL\n");
        return;
    }
    for (size_t i = 0; i < size_hash_table; i++) {
        ItemMap* item = hash_table->items[i];
        if (item == NULL) {
            List* list = hash_table->buckets[i];
            if (list != NULL) {
                hash_table->items[i] = list->data;
                free_memory_list(list);
                hash_table->buckets[i] = NULL;
            }
        }
    }
}