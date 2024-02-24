#include "hashtable.h"
#include "list.h"
int main(void)
{
	HashTable* hTable= allocate_memory_table(100);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		exit(0);
	}
	create_item(hTable,'g', CHAR_TYPE, 1, INT_TYPE);
	create_item(hTable, "Pasha", STRING_TYPE, 2, INT_TYPE);
	create_item(hTable, "Sweta", STRING_TYPE, 16, INT_TYPE);
	create_item(hTable, "Denis", STRING_TYPE, 3, INT_TYPE);
	create_item(hTable, 5, INT_TYPE, 3, INT_TYPE);
	print_all_hash_table(hTable);
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
