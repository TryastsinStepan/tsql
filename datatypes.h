#pragma once
#include <stdlib.h>   
#include <stdio.h>
#include <malloc.h>
#include "utils.h"
typedef enum DataType {
	STRING_TYPE,
	INT_TYPE,
	CHAR_TYPE
}DataType;
void* detmtypedata(ptr* item);