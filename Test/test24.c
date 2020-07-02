#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <lst/List.h>
#define N 100000

int intCompare_asc(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int intCompare_desc(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
}

int main(void)
{
	srand(time(0));
	LinkedList* list = newLinkedList();
	for(int i = 0; i != N; ++i)
		add(list, rand() % 1000);

	sort(list, intCompare_asc);
	int i = 0;
	Node* aux = list->pEnd;
	while(aux != NULL)
	{
		i++;
		printf("%d\n", *(int*)aux->object);
		aux = aux ->prev;
	}
	printf("%d = %d\n", i, list->count);
	getchar();
	foreach(int, num, list) 
		printf("%d\n", *num);
	printf("Ultimo elemento: %d\n", *(int*)list->pEnd->object);
	printf("La lista quedo ordenada de forma ascendente:\n\n");
	getchar();
	
	sort(list, intCompare_desc);
	foreach(int, num, list)
		printf("%d\n", *num);
	printf("Ultimo elemento: %d\n", *(int*)list->pEnd->object);
	printf("La lista quedo ordenada de forma descendente:\n\n");
	
	delete(list);
    return 0;
}
