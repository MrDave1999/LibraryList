#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

int main()
{
	LinkedList* listNumber = newLinkedList();
	
	enqueue(listNumber, 12);
	enqueue(listNumber, 4);
	enqueue(listNumber, 1);
	enqueue(listNumber, -23);
	printf("(1) isEmpty: %d, size: %d, Top element: %d\n\n", isEmpty(listNumber), size(listNumber), *(int*)getTop(listNumber));
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
	enqueue(listNumber, 1);
	enqueue(listNumber, 2);
	push(listNumber, 3);
	push(listNumber, 4);
	enqueue(listNumber, 5);
	
	foreach(int, number, listNumber)
		printf("%d\n", *number);
	
	clear(listNumber);
	
	foreach(int, number, listNumber)
		printf("%d\n", *number);
		
	delete(listNumber);
	
	getchar();
    return 0;
}
