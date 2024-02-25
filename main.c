#include "hmap.h"
int main(void)
{
	HashTable* hTable= allocate_memory_table(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		exit(0);
	}
	create_buckets();
	create_item(hTable, 'a', CHAR_TYPE, 1, INT_TYPE);
	create_item(hTable, 'b', CHAR_TYPE, 2, INT_TYPE);
	create_item(hTable, 'l', CHAR_TYPE, 3, INT_TYPE);
	create_item(hTable, 'd', CHAR_TYPE, 4, INT_TYPE);
	create_item(hTable, 'f', CHAR_TYPE, 5, INT_TYPE);
	create_item(hTable, 'g', CHAR_TYPE, 6, INT_TYPE);
	create_item(hTable, 'h', CHAR_TYPE, 7, INT_TYPE);
	create_item(hTable, 'i', CHAR_TYPE, 8, INT_TYPE);
	create_item(hTable, 'n', CHAR_TYPE, 9, INT_TYPE);
	print_all_hash_table(hTable);
	delete_elem(hTable, 'l', CHAR_TYPE);
	print_all_hash_table(hTable);
	free_memory_table(hTable);

	return 0;
}



