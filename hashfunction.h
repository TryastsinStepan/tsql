#pragma once
#include "datatypes.h"
#include "utils.h"
i32_t hash_function_string(ptr key,DataType type);
i32_t hash_function_char(ptr key, DataType type);
i32_t hash_function_int(ptr key, DataType type);
i32_t hash_function_double(ptr key, DataType type);

