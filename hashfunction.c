#include "hashfunction.h"

i32_t hash_function_string(ptr key, DataType type, i32_t maxindex) {
    uint64_t hash_value = 0;
    char* str = (char*)key;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        hash_value = (hash_value * 31 + (uint64_t)str[i]) % maxindex;
    }
    return (i32_t)hash_value;
}

i32_t hash_function_char(ptr key, DataType type, i32_t maxindex) {
    uint64_t hash_value = 0;
    char* str = (char*)key;
    while (*str) {
        hash_value = (hash_value * 31) + *str;
        str++;
    }
    return (i32_t)hash_value;
}

i32_t hash_function_int(ptr key, DataType type, i32_t maxindex) {
    int num = *(int*)key;
    uint64_t hash_value = (uint64_t)num % maxindex;
    return (i32_t)hash_value;
}
