#include "hashtable.h"
#include "list.h"
int main(void)
{
	HashTable* hTable= allocate_memory_table(100);
	if (hTable == NULL) {
		printf("Error: Unable to allocate memory.\n");
		exit(0);
	}
	create_bucket(hTable,"Stepan", STRING_TYPE, 1, INT_TYPE);
	create_bucket(hTable, "Pasha", STRING_TYPE, 2, INT_TYPE);
	create_bucket(hTable, "Denis", STRING_TYPE, 3, INT_TYPE);
	
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
