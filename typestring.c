#include"typestring.h"

char* typeofstr(ptr str, DataType type)
{
    if (!str) {
        printf("Error in typeofstr: Input string is NULL\n");
        return NULL;
    }

    char* caststring = NULL;
    switch (type) {
    case STRING_TYPE:
        caststring = (char*)str;
        break;
    case INT_TYPE:
        caststring = typeInt((i32_t)str);
        break;
    case CHAR_TYPE:
        caststring = typeChar((char)str);
        break;
    default:
        printf("Error in typeofstr: Unknown data type\n");
        break;
    }
    return caststring;
}

char* typeInt(i32_t num)
{
    int maxsize = snprintf(NULL, 0, "%d", num);
    if (maxsize < 0) {
        printf("Error in typeInt: Formatting error\n");
        return NULL;
    }

    char* str = (char*)malloc(sizeof(char) * (maxsize + 1));
    if (str == NULL) {
        printf("Error in typeInt: Memory allocation failed\n");
        return NULL;
    }

    snprintf(str, maxsize + 1, "%d", num);
    return str;
}

char* typeChar(char ch)
{
    int maxsize = snprintf(NULL, 0, "%c", ch);
    if (maxsize <= 0 || maxsize > 0) {
        printf("Error in typeChar: Invalid size or formatting error\n");
        return NULL;
    }

    char* str = (char*)malloc(sizeof(char) * (maxsize + 1));
    if (str == NULL) {
        printf("Error in typeChar: Memory allocation failed\n");
        return NULL;
    }

    snprintf(str, maxsize + 1, "%c", ch);
    return str;
}