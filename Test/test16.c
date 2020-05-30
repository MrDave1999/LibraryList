#include <stdio.h>
#include <stdlib.h> 
#include <lst/List.h>

int main()
{
	for(int i = 0; i != 10; ++i)
		newArrayList();
	
	for(int i = 0; i != 5; ++i)
		newSortedList(NULL);
	
	for(int i = 0; i != 4; ++i)
	{
		newQueue();
		newStack();
	}
	
	for(int i = 0; i != 6; ++i)
		newLinkedList();
	
	printf("Count ArrayList: %d\n", registers[ARRAYLIST].count);
	printf("Count LinkedList: %d\n", registers[LINKEDLIST].count);
	
	freeAll();
	
	LinkedList* lk[5];
	ArrayList* al[5];
	
	for(int i = 0; i != 5; ++i)
	{
		lk[i] = newLinkedList();
		al[i] = newArrayList();
	}
	
	printf("\nCount ArrayList: %d\n", registers[ARRAYLIST].count);
	printf("Count LinkedList: %d\n", registers[LINKEDLIST].count);
	
	delete(lk[0]);
	delete(lk[3]);
	delete(al[2]);
	delete(al[0]);
	
	printf("\nCount ArrayList: %d\n", registers[ARRAYLIST].count);
	printf("Count LinkedList: %d\n", registers[LINKEDLIST].count);
	
	freeAll();
	
	printf("\nCount ArrayList: %d\n", registers[ARRAYLIST].count);
	printf("Count LinkedList: %d\n", registers[LINKEDLIST].count);
	
	getchar();
    return 0;
}
