#include "hashtable.h"
int main(void)
{
	HashTable* hTable= allocate_memory_table(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		freememtable(hTable);
		exit(0);
	}
	create_bucket(1,"Hello", hTable);
	print_hash_table(hTable);
	return 0;
}
