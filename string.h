#pragma once
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
typedef struct MyString {
	ptr str;
	i32_t size;
}MyString;

 MyString* allocateMemory(ptr str);
 i32_t strlen(ptr str);