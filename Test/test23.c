#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <lst/List.h>
#define N 1000

int intCompare_asc(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int intCompare_desc(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
}

int main()
{
	srand(time(0));
	ArrayList* list = newArrayList();
	for(int i = 0; i != N; ++i)
		add(list, rand() % 1000);
	
	sort(list, intCompare_asc);
	foreach(int, num, list)
		printf("%d\n", *num);
	printf("La lista quedo ordenada de forma ascendente:\n\n");
	getchar();
	
	sort(list, intCompare_desc);
	foreach(int, num, list)
		printf("%d\n", *num);
	printf("La lista quedo ordenada de forma descendente:\n\n");
	
	delete(list);
    return 0;
}
