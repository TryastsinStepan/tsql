#pragma once
/*
    CREATE TABLE Users (
    UserID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Email VARCHAR(100),
    Age INT
); */
#include"datatypes.h"
#include"utils.h"
#include"string.h"
static i32_t index = 0;
typedef struct ItemTable {
    ptr data;
    DataType type;

}ItemTable;
typedef struct Table {
    MyString* name;
    ItemTable **item;
    i32_t count;

}Table;
Table* createtsqltable(MyString* name, DataType type, ptr data, i32_t size);
void createItem(Table* table, DataType type, ptr data);
ItemTable* initDataType(DataType type, ptr data)
