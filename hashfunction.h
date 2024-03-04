#pragma once

#include "datatypes.h"
#include <stdio.h>
#include "utils.h"
#include "word.h"

i32_t hash_function_string(ptr key, i32_t maxindex);

i32_t hash_function_char(ptr key, i32_t maxindex);

i32_t hash_function_int(ptr key, i32_t maxindex);

i32_t hash_function_word(ptr key, i32_t maxindex);

