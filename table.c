#include"table.h"

Table* createtsqltable(MyString* name, MyString* nameCol,DataType typeCol, i32_t count) {
    if (!name) {
        printf("You didn't name the table\n");
        return NULL;
    }
    if (!nameCol) {
        printf("You didn't name the column\n");
        return NULL;
    }
    Table* table = (Table*)malloc(sizeof(Table));
    if (!table) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    table->name = name;
    table->nameCol = nameCol;
    table->typeCol = typeCol;
    table->item = (ItemTable**)calloc(100, sizeof(ItemTable*));
    if (!table->item) {
        printf("Memory allocation failed\n");
        free(table);
        return NULL;
    }
    for (i32_t i = 0; i < 100; i++) {
        table->item[i] = NULL;
    }
    table->count = count;
    return table;
}

void createItem(Table* table, DataType type, ptr data) {
    if (!table) {
        printf("Table is not initialized\n");
        return;
    }
    if (index >= 100) {
        printf("Table capacity exceeded\n");
        return;
    }
    table->item[index] = initDataType(table,type, data);
    index++;
}

ItemTable* initDataType(Table* table,DataType type, ptr data) {
    ItemTable* item = (ItemTable*)malloc(sizeof(ItemTable));
    if (!item) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    item->type = type;
    switch (type) {
    case INT_TYPE:
        item->dataCol = malloc(sizeof(int));
        if (!item->dataCol) {
            printf("Memory allocation failed\n");
            free(item);
            return NULL;
        }
        *(int*)(item->dataCol) = *(int*)data;
        break;
    case STRING_TYPE:
        item->dataCol = ((char*)data);
        if (!item->dataCol) {
            printf("Memory allocation failed\n");
            free(item);
            return NULL;
        }
        break;
    case CHAR_TYPE:
        item->dataCol = malloc(sizeof(char));
        if (!item->dataCol) {
            printf("Memory allocation failed\n");
            free(item);
            return NULL;
        }
        *(char*)(item->dataCol) = *(char*)data;
        break;
    default:
        free(item);
        printf("Unsupported data type\n");
        return NULL;
    }
    ItemTable* checkItem = comapareDataBetweenDataAndDataInCol(item, table);
    return checkItem;
}

void print(Table* table) {
    if (!table) {
        printf("Table is not initialized\n");
        return;
    }
    printf("\t\t ------Table------\n");
    for (i32_t i = 0; i < index; i++) {
        if (table->item[i] != NULL) {
            printf("Table:index:%d,%s,Column:%s,Type:String Data:%s\n", i,(char*) table->name->str, (char*)table->nameCol->str ,  (char*)table->item[i]->dataCol);
        }
    }
}

void freeTable(Table* table) {
    if (!table) {
        return;
    }
    for (size_t i = 0; i < index; i++)
    {
        free(table->item[i]);
    }
    free(table->item);
    free(table);
    printf("Memory was cleared\n");
    return;
}

ItemTable* comapareDataBetweenDataAndDataInCol(ItemTable* item, Table* table)
{
    if (item->type == table->typeCol) {
        return item;
    }
    return NULL;
}
