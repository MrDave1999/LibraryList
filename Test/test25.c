#include <stdio.h>
#include <lst/List.h>

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6, 1};
	int size = sizeof nums / sizeof(int);
	LinkedList* lk = newLinkedList();
	ArrayList* al = newArrayList();

	for(int i = 0; i != size; ++i)
	{
		add(lk, nums[i]);
		add(al, nums[i]);
	}
	
	printf("Lista inversa (LinkedList):\n");
	reverse(lk);
	foreach(int, n, lk)
		printf("%d\n", *n);
	
	getchar();
	printf("\nLista inversa (ArrayList):\n");
	reverse(al);
	foreach(int, n, al)
		printf("%d\n", *n);
	
	delete(lk);
	delete(al);
    return 0;
}
