#include <stdio.h>
#include <stdlib.h> /* rand() */
#include <lst/List.h>

int intCompare_asc(const void* o1, const void* o2)
{
	return *(int*)o1 - *(int*)o2;
}

int intCompare_desc(const void* o1, const void* o2)
{
	return *(int*)o2 - *(int*)o1;
}

int main()
{
	LinkedList* list_num = newLinkedList();
	
	for(int i = 0; i != 100; ++i)
		add(list_num, rand() % 1000);
	
	printf("Lista desordenada:\n");
	foreach(int, num, list_num)
		printf("%d\n", *num);
	
	bsort(list_num, intCompare_asc);
	printf("Lista ordenada de forma ascedente:\n");
	foreach(int, num, list_num)
		printf("%d\n", *num);
	
	bsort(list_num, intCompare_desc);
	printf("Lista ordenada de forma descendente:\n");
	foreach(int, num, list_num)
		printf("%d\n", *num);
	
	delete(list_num);
	getchar();
    return 0;
}
