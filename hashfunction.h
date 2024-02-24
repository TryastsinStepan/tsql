#pragma once
#include "datatypes.h"
#include <stdio.h>
#include "utils.h"
i32_t hash_function_string(ptr key,DataType type, i32_t maxindex);
i32_t hash_function_char(ptr key, DataType type, i32_t maxindex);
i32_t hash_function_int(ptr key, DataType type, i32_t maxindex);

