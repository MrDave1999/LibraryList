#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

boolean intEquals(const void* p, const void* key)
{
	return *(int*)p == *(int*)key;
}

int main()
{
	Queue* listNumber = newQueue();
	int key;
	enqueue(listNumber, 12);
	enqueue(listNumber, 4);
	enqueue(listNumber, 1);
	enqueue(listNumber, -23);
	printf("(1) isEmpty: %d, size: %d, Front element: %d\n\n", isEmpty(listNumber), size(listNumber), *(int*)getFront(listNumber));
	foreach(int, number, listNumber)
		printf("%d\n", *number);
		
	int* number = dequeue(listNumber);
	printf("One data in list: %d\n", *number);
	free(number);
	
	printf("(2) isEmpty: %d, size: %d\n\n", isEmpty(listNumber), size(listNumber));
	foreach(int, number, listNumber)
		printf("%d\n", *number);
	
	while((number = dequeue(listNumber)) != NULL)
	{
		printf("Data deleted: %d\n", *number);
		free(number);
	}

	printf("(3) isEmpty: %d, size: %d\n\n", isEmpty(listNumber), size(listNumber));
	enqueue(listNumber, 2000);
	enqueue(listNumber, 232);
	enqueue(listNumber, 500);
	key = 232;
	printf("\nElement search: %d\n", *(int*)find(listNumber, &key, intEquals));
	
	clear(listNumber);
	
	foreach(int, number, listNumber)
		printf("%d\n", *number);
		
	delete(listNumber);
	
	getchar();
    return 0;
}
