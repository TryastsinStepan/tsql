#include "hashtable.h"
int main(void)
{
	HashTable* hTable= allocate_memory_table(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		free_memory_table(hTable);
		exit(0);
	}
	create_bucket(hTable,"Stepan", STRING_TYPE, 1, INT_TYPE);
	create_bucket(hTable, "Pasha", STRING_TYPE, 2, INT_TYPE);
	create_bucket(hTable, "Denis", STRING_TYPE, 3, INT_TYPE);
	print_all_hash_table(hTable);
	return 0;
}
