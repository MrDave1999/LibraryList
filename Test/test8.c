#include <stdio.h>
#include <string.h>
#include <lst/List.h>

int nameCompare_asc(const void* o1, const void* o2)
{
	return strcmp(o1, o2);
}

int nameCompare_desc(const void* o1, const void* o2)
{
	return strcmp(o2, o1);
}

int main()
{
	ArrayList* listNames = newArrayList();
	
	add(listNames, "David");
	add(listNames, "Jose");
	add(listNames, "Joel");
	add(listNames, "Jaime");
	add(listNames, "Guillermo");
	
	printf("Lista desordenada:\n");
	foreach(char, name, listNames)
		printf("%s\n", name);
		
	printf("\nLista ordenada de forma ascendente:\n");
	bsort(listNames, nameCompare_asc);
	
	foreach(char, name, listNames)
		printf("%s\n", name);
	
	printf("Index position: %d\n", bSearch_i(listNames, "Jaime", nameCompare_asc));
	printf("Index position: %d\n", bSearch_i(listNames, "Pepito", nameCompare_asc));
	
	printf("\nLista ordenada de forma descendente:\n");
	bsort(listNames, nameCompare_desc);
	
	foreach(char, name, listNames)
		printf("%s\n", name);
		
	printf("Index position: %d\n", bSearch_i(listNames, "David", nameCompare_desc));
	printf("Index position: %d\n", bSearch_i(listNames, "Joelito", nameCompare_desc));
	
	delete(listNames);
	getchar();
    return 0;
}
