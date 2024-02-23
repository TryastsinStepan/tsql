#include "hashtable.h"
int main(void)
{
	HashTable* hTable= allocate_memory_table(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		free_memory_table(hTable);
		exit(0);
	}
	create_bucket(hTable,1,"Hello",STRING_TYPE);
	print_hash_table(hTable);
	return 0;
}
