#include <stdio.h>
#include <lst/List.h>
#include <stdlib.h>

int intCompare(const void* o1, const void* o2)
{
	return *(int*)o1 - *(int*)o2;
}

boolean intEquals(const void* p, const void* key)
{
	return *(int*)p == *(int*)key;
}

int main()
{
	int key, num;
	int* numSearch;
	srand(time(NULL));
	LinkedList* list = newSortedList(intCompare);
	
	for(int i = 0; i != 30; ++i)
		addSorted(list, rand() % 1000);

	foreach(int, n, list)
		printf("%d\n", *n);
	
	printf("Ingrese una clave: ");
	scanf("%d", &key);
	
	printf("\nIngrese un nuevo numero: ");
	scanf("%d", &num);
	
	if((numSearch = findSorted(list, &key, &num, intEquals)) == NULL)
		printf("Ese elemento no se encuentra en la lista\n");
	else
	{
		*numSearch = num;
		foreach(int, n, list)
		{
			if(*n == num)
				printf("Numero modificado: ");
			printf("%d\n", *n);
		}
	}
	delete(list);
    return 0;
}
