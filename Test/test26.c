#include <stdio.h>
#include <lst/List.h>

int main(void)
{
	int x, y;
	int nums[] = {5, 8, 9, 10, 15, 16, 18, 19, 22, 26};
	int size = sizeof nums / sizeof(int);
	LinkedList* lk = newLinkedList();
	ArrayList* al = newArrayList();

	for(int i = 0; i != size; ++i)
	{
		add(lk, nums[i]);
		add(al, nums[i]);
	}
	
	printf("(LinkedList): Ingrese los valores:\n");
	scanf("%d %d", &x, &y);
	rremove(lk, x, y);
	
	push(lk, 12);
	add(lk, 27);
	
	foreach(int, n, lk)
		printf("%d\n", *n);
	
	getchar();
	
	printf("(ArrayList): Ingrese los valores:\n");
	scanf("%d %d", &x, &y);
	rremove(al, x, y);
	
	add(al, 27);
	
	foreach(int, n, al)
		printf("%d\n", *n);
	
	delete(lk);
	delete(al);
    return 0;
}
