#include"string.h"

MyString* createstr(ptr str, DataType type) {
    if (str == NULL) {
        printf("Error: String is NULL\n");
        return NULL;
    }

    MyString* mystr = (MyString*)malloc(sizeof(MyString));
    if (!mystr) {
        printf("Error: MyString is NULL\n");
        return NULL;
    }

    char* cstring = typeofstr(str, type);
    if (cstring == NULL) {
        printf("Error: Unable to determine string type\n");
        free(mystr);
        return NULL;
    }

    i32_t len = strlen(cstring);
    mystr->str = (ptr)malloc(sizeof(char) * (len + 1));
    if (!mystr->str) {
        printf("Error: Memory allocation failed\n");
        free(mystr);
        return NULL;
    }

    copymystring(mystr->str, cstring);
    mystr->size = len;
    mystr->type = type;
    return mystr;
}

i32_t strlen(ptr str) {
    if (str == NULL) {
        printf("Error: String is NULL\n");
        return 0;
    }
    char* cstring = str;
    i32_t size = 0;
    while (*cstring++) {
        size++;
    }
    return size;
}

void printstr(ptr str) {
    if (!str) {
        printf("Error: String is NULL\n");
        return;
    }
    MyString* string = str;
    printf("String: %s\n",(char*) string->str);
    printf("Size: %d\n", string->size);
}

void copymystring(ptr first, ptr second) {
    char* stringFirst = first;
    char* stringSecond = second;
    if (!stringFirst) {
        printf("Error: String is NULL\n");
        return;
    }
    if (!stringSecond) {
        printf("Error: String is NULL\n");
        return;
    }
    while ((*stringFirst++ = *stringSecond++) != '\0') {}
}