#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

void foo(ArrayList* al, int value)
{
	foreach(int, num, al)
	{
		if(*num == value)
			remv(al);
	}
	
	printf("\nCount ArrayList: %d\n", size(al));
}

int main()
{
	int nums[] = {1, 4, 10, 3, 5, 7, 0};
	ArrayList* al = newArrayList();
	for(int i = 0; i != 7; ++i)
		add(al, nums[i]);
	
	setDefault(al);
	while(hasNext(al))
	{
		int* n = getNext(al);
		printf("%d\n", *n);
		remv(al);
		
	}

	printf("\nCount ArrayList: %d\n", size(al));
	
	for(int i = 0; i != 7; ++i)
		add(al, nums[i]);
	
	foreach(int, num, al)
		printf("%d\n", *num);

	foo(al, 1);
	foo(al, 0);
	foo(al, 3);
	foo(al, 4);
	foo(al, 7);
	foo(al, 10);
	foo(al, 5);
	foreach(int, num, al)
		printf("%d\n", *num);
		
	delete(al);
    return 0;
}
