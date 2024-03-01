#include"table.h"

Table* createtsqltable(MyString* name, DataType type, ptr data, i32_t count)
{
    if (!name) {
        printf("You didn't name the table\n");
        return NULL; 
    }
    Table* table = (Table*)malloc(sizeof(Table));
    if (!table) {
        printf("Memory allocation failed\n");
        return NULL; 
    }
    table->name = name;
    table->item = (ItemTable**)calloc(100, sizeof(ItemTable));
    if (!table->item) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (i32_t i = 0; i < 100; i++)
    {
        table->item[i] = NULL;
    }
    table->count = count;
    return table;
}

void createItem(Table* table, DataType type, ptr data)
{
    if (!table) {
        printf("You didn't name the table\n");
        return NULL;
    }
    table->item[index] = initDataType(type, data);


}

ItemTable* initDataType(DataType type, ptr data)
{
    switch (type) {
    case INT_TYPE:
        return (int)data;
    case STRING_TYPE:
        return (char*)data;
    case CHAR_TYPE:
        return (char)data;
    }
    return NULL;
}
