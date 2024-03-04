#include "hashfunction.h"

i32_t hash_function_string(ptr key, i32_t maxindex) {
    uint64_t hash_value = 0;
    char* str = (char*)key;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        hash_value = (hash_value << 5) + (uint64_t)str[i];
    }
    return (i32_t)(hash_value % maxindex); 
}

i32_t hash_function_char(ptr key, i32_t maxindex) {
    uint64_t hash_value = 0;
    char str = (char)key;
    hash_value = (hash_value * 31) + (int)str;
    return (i32_t)hash_value% maxindex;
}

i32_t hash_function_int(ptr key, i32_t maxindex) {
    int num = (int)key;
    uint64_t hash_value = (uint64_t)num % maxindex;
    return (i32_t)hash_value;
}
i32_t hash_function_word(ptr key, i32_t maxindex) {
    Word* word = (Word*)key;
    char* str = word->lexema;
    uint64_t num = word->id;
    i32_t hash_value = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        hash_value = (uint64_t)num % maxindex + (hash_value << 5) + (uint64_t)str[i];
    }
    return hash_value% maxindex;
}
