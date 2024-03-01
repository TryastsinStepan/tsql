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
    ptr dataCol;
    DataType type;

}ItemTable;
typedef struct Table {
    MyString* name;
    ItemTable **item;
    MyString* nameCol;
    i32_t count;

}Table;
Table* createtsqltable(MyString* name, MyString* nameCol, i32_t count);
void createItem(Table* table, DataType type, ptr data);
ItemTable* initDataType(DataType type, ptr data);
void freeTable(Table* table);
void print(Table* table);
