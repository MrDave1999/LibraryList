#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

boolean intEquals(const void* p1, const void* key)
{
	return *(int*)p1 == *(int*)key;
}

void printInfo(ArrayStack* as, int i)
{
	printf("\n->(%d) Count: %d, Top: %d, Max: %d\n", i, size(as), *(int*)getTop(as), as->max);
}

int main()
{
	int key;
	int nums[] = {1, 4, 10, 3, 5, 7, 0};
	ArrayStack* as = newArrayStack(7);
	
	for(int i = 0; i != 7; ++i)
		push(as, nums[i]);
	
	printInfo(as, 1);
	foreach(int, num, as)
		printf("%d\n", *num);
	
	int* v;
	for(int i = 0; i != 7; ++i)
	{
		v = pop(as);
		printf("Delete: %d\n", *v);
		free(v);
	}
	printf("Top: %d, count: %d\n", as->top, as->count);
	push(as, 2);
	foreach(int, num, as)
		printf("%d\n", *num);
	
	clear(as);
	push(as, 100);
	push(as, 5);
	push(as, 10);
	push(as, 100);
	printInfo(as, 2);
	
	foreach(int, num, as)
		printf("%d\n", *num);
	
	key = 5;
	int* val = find(as, &key, intEquals);
	if(val != NULL)
		printf("Valor encontrado: %d\n", *val);
	else
		printf("Elemento no encontrado\n");
	delete(as);
    return 0;
}
