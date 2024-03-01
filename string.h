#pragma once
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include"datatypes.h"
#include"typestring.h"
typedef struct MyString {
	ptr str;
	i32_t size;
	DataType type;
}MyString;
 MyString* createstr(ptr str,DataType type);
 void copymystring(ptr first, ptr second);
 i32_t strlen(ptr str);
 void printstr(ptr str);
 void free_string(MyString* string);
