#include"string.h"

MyString* allocateMemory(ptr str)
{
	if (!str) {
		printf("Error: String is NULL\n");
		return;
	}
	MyString* mystr = (MyString*)malloc(sizeof(MyString));
	if(!str) {
		printf("Error: MyString is NULL\n");
		return;
	}
	i32_t len = strlen(str);
	mystr->str = (MyString*) malloc(sizeof(MyString) * (len+1));
	if (!mystr->str) {
		printf("Error: Memory allocation failed\n");
		free(mystr);
		return NULL;
	}
	copymystring(mystr->str, str);
	mystr->size = len;
	return mystr;
}

i32_t strlen(ptr str)
{
	char* string = str;
	i32_t size = 0;
	if (!string) {
		printf("Error: String is NULL\n");
		return;
	}
	while (*string++) {
		size++;
	}
	return size;
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
	while (*stringFirst++ = *stringSecond++) {}
}
