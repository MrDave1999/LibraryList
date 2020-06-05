#include <stdio.h>
#include <lst/List.h>
#include <stdlib.h>

LinkedList* list;

int intCompare(const void* o1, const void* o2)
{
	return *(int*)o1 - *(int*)o2;
}

boolean intEquals(const void* p, const void* key)
{
	return *(int*)p == *(int*)key;
}

void showDesc()
{
	printf("\nDescendente:\n");
	Node* aux = list->pEnd;
	while(aux != NULL)
	{
		printf("%d\n", *(int*)aux->object);
		aux = aux->prev;
	}
}

void showAsc()
{
	printf("\nAscendente:\n");
	foreach(int, num, list)
		printf("%d\n", *num);
}

int main()
{
	int key, num;
	int* numSearch;
	int arr[] = {4, 8, 1, 12, 20, 16, 24, -1};
	list = newSortedList(intCompare);
	for(int i = 0; i != 8; ++i)
		addSorted(list, arr[i]);
	showAsc();
	printf("Ingrese una clave: ");
	scanf("%d", &key);
	printf("\nIngrese un nuevo numero: ");
	scanf("%d", &num);
	if((numSearch = findSorted(list, &key, &num, intEquals)) == NULL)
		printf("Ese elemento no se encuentra en la lista\n");
	else
	{
		*numSearch = num;
		showDesc();
		showAsc();
	}
	delete(list);
    return 0;
}
