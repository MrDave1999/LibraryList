#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

int main()
{
	Queue* listNumber = newQueue();
	
	enqueue(listNumber, 12);
	enqueue(listNumber, 4);
	enqueue(listNumber, 1);
	enqueue(listNumber, -23);
	printf("(1) isEmpty: %d, size: %d\n\n", isEmpty(listNumber), size(listNumber));
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
	
	clear(listNumber);
	
	foreach(int, number, listNumber)
		printf("%d\n", *number);
		
	delete(listNumber);
	
	getchar();
    return 0;
}
