#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

int intCompare(const void* o1, const void* o2)
{
	return *(int*)o1 - *(int*)o2;
}

int main()
{
	LinkedList* nums = newLinkedList();
	ArrayList* lists_f;
	add(nums, 24);
	add(nums, 22);
	add(nums, 67);
	add(nums, 19);
	add(nums, 24);
	add(nums, 22);
	
	printf("Valor maximo: %d\n", *(int*)max(nums, intCompare));
	printf("Valor minimo: %d\n", *(int*)min(nums, intCompare));
	
	clear(nums);
	
	if(max(nums, intCompare) == NULL)
		printf("Error: No hay valor maximo porque esta vacia la lista\n");
	
	add(nums, 22);
	
	printf("Max: %d\n", *(int*)max(nums, intCompare));
	printf("Min: %d\n", *(int*)min(nums, intCompare));
	
	delete(nums);
	
	lists_f = newArrayList();
	add(lists_f, -2);
	add(lists_f, -232);
	add(lists_f, -343);
	add(lists_f, -23);
	add(lists_f, -22);
	add(lists_f, 232);
	
	printf("Valor maximo: %d\n", *(int*)max(lists_f, intCompare));
	printf("Valor minimo: %d\n", *(int*)min(lists_f, intCompare));
	
	clear(lists_f);
	
	if(min(lists_f, intCompare) == NULL)
		printf("Error: No hay valor minimo porque esta vacia la lista\n");
	
	add(lists_f, -23);
	
	printf("Max: %d\n", *(int*)max(lists_f, intCompare));
	printf("Min: %d\n", *(int*)max(lists_f, intCompare));
	
	delete(lists_f);
	
	getchar();
    return 0;
}
