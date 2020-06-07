#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

void foo(LinkedList* lk, int value)
{
	foreach(int, num, lk)
	{
		if(*num == value)
			remv(lk);
	}
	printf("\nCount LinkedList: %d\n", size(lk));
}

int main()
{
	int nums[] = {1, 4, 10, 3, 5, 7, 0};
	LinkedList* lk = newLinkedList();
	for(int i = 0; i != 7; ++i)
		add(lk, nums[i]);
	
	setDefault(lk);
	while(hasNext(lk))
	{
		int* n = getNext(lk);
		printf("%d\n", *n);
		remv(lk);
	}

	printf("\nCount LinkedList: %d\n", size(lk));
	
	for(int i = 0; i != 7; ++i)
		add(lk, nums[i]);
	
	foreach(int, num, lk)
		printf("%d\n", *num);
	
	foo(lk, 1);
	foo(lk, 0);
	foo(lk, 3);
	foo(lk, 4);
	foo(lk, 7);
	foo(lk, 10);
	foo(lk, 5);
	foreach(int, num, lk)
		printf("%d\n", *num);
	
	delete(lk);
    return 0;
}
