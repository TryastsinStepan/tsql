#include "hashtable.h"
#include "list.h"
int main(void)
{
	HashTable* hTable= allocate_memory_table(10);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		exit(0);
	}
	create_item(hTable,"Masha", STRING_TYPE, 1, INT_TYPE);
	create_item(hTable, "Masha", STRING_TYPE, 2, INT_TYPE);
	create_item(hTable, "Masha", STRING_TYPE, 3, INT_TYPE);
	create_item(hTable, "Masha", STRING_TYPE, 4, INT_TYPE);
	create_item(hTable, "Masha", STRING_TYPE, 5, INT_TYPE);
	create_item(hTable, "Sasha", STRING_TYPE, 6, INT_TYPE);
	create_item(hTable, "Sasha", STRING_TYPE, 7, INT_TYPE);
	create_item(hTable, "Masha", STRING_TYPE, 8, INT_TYPE);
	create_item(hTable, "Masha", STRING_TYPE, 9, INT_TYPE);
	print_all_hash_table(hTable);
	free_memory_table(hTable);
	return 0;
}

//int main(void)
//{
//	List* list = allocate_memory_list();
// 	if (list == NULL) {
// 	     printf("Error: Unable to allocate memory.\n");
//		 exit(0);
//	}
//	push(list, (char*)"Hello");
//	push(list, (char*)"My");
//	push(list, (char*)"Name");
//	print_list(list);
//}
