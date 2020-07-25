#include <stdio.h>
#include <stdlib.h> 
#include <lst/List.h>

int main()
{
	for(int i = 0; i != 10; ++i)
		newArrayList();
	
	for(int i = 0; i != 5; ++i)
	{
		newLinkedQueue();
		newLinkedStack();
	}
		
	for(int i = 0; i != 4; ++i)
	{
		newArrayQueue(10);
		newArrayStack(11);
	}
	
	for(int i = 0; i != 6; ++i)
		newLinkedList();
	
	for(int i = 0; i != 3; ++i)
		newSortedList(NULL);
	
	printf("ArrayList: %d\n", getCountStructs(ARRAYLIST));
	printf("LinkedList: %d\n", getCountStructs(LINKEDLIST));
	printf("ArrayStack: %d\n", getCountStructs(ARRAYSTACK));
	printf("ArrayQueue: %d\n", getCountStructs(ARRAYQUEUE));
	printf("LinkedStack: %d\n", getCountStructs(LINKEDSTACK));
	printf("LinkedQueue: %d\n", getCountStructs(LINKEDQUEUE));	
	
	freeAll(ARRAYLIST);
	freeAll(LINKEDLIST);
	freeAll(ARRAYSTACK);
	freeAll(ARRAYQUEUE);
	freeAll(LINKEDSTACK);
	freeAll(LINKEDQUEUE);
	
	printf("ArrayList: %d\n", getCountStructs(ARRAYLIST));
	printf("LinkedList: %d\n", getCountStructs(LINKEDLIST));
	printf("ArrayStack: %d\n", getCountStructs(ARRAYSTACK));
	printf("ArrayQueue: %d\n", getCountStructs(ARRAYQUEUE));
	printf("LinkedStack: %d\n", getCountStructs(LINKEDSTACK));
	printf("LinkedQueue: %d\n", getCountStructs(LINKEDQUEUE));	
	
	getchar();
    return 0;
}
