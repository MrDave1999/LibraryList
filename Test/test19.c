#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

boolean intEquals(const void* p1, const void* key)
{
	return *(int*)p1 == *(int*)key;
}

void printInfo(ArrayQueue* aq, int i)
{
	printf("\n->(%d) Count: %d, Front: %d, Max: %d, N: %d\n", i, size(aq), *(int*)getFront(aq), aq->max, aq->n);
}

int main()
{
	int key;
	int nums[] = {1, 4, 10, 3, 5};
	ArrayQueue* aq = newArrayQueue(6);
	
	for(int i = 0; i != 5; ++i)
		enqueue(aq, nums[i]);
	
	printInfo(aq, 1);
	
	foreach(int, num, aq)
		printf("%d\n", *num);
	
	int* v;
	for(int i = 0; i != 5; ++i)
	{
		v = dequeue(aq);
		printf("Delete: %d\n", *v);
		free(v);
	}
	printf("begin %d\n", aq->begin);
	enqueue(aq, 2);
	foreach(int, num, aq)
		printf("%d\n", *num);
	
	clear(aq);
	enqueue(aq, 200);
	enqueue(aq, 5);
	enqueue(aq, 10);
	enqueue(aq, 100);
	printInfo(aq, 2);
	
	foreach(int, num, aq)
		printf("%d\n", *num);
	
	key = 100;
	int* val = find(aq, &key, intEquals);
	if(val != NULL)
		printf("Valor encontrado: %d\n", *val);
	else
		printf("Elemento no encontrado\n");
	delete(aq);
    return 0;
}
