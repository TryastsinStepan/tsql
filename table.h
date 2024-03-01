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

typedef struct Table {
    MyString* name;
    DataType type;
    ptr data;
    i32_t count;

}Table;
Table* createtsqltable(MyString* name, DataType type, ptr data, i32_t size);
