#include "hashtable.h"
int main(void)
{
	HashTable* hTable= allocmemorytable(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		freememtable(hTable);
		exit(0);
	}
	createbuck(1,"Hello", hTable);
	printhashtable(hTable);
	return 0;
}
