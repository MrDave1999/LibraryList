#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <lst/List.h>

boolean nameEquals(const void* p, const void* key)
{
	return strcmp(p, key) == 0;
}

int main()
{
	Stack* listNames = newStack();
	push(listNames, "David");
	push(listNames, "Roberto");
	push(listNames, "Joel");
	push(listNames, "Josias");
	printf("(1) isEmpty: %d, size: %d, Top element: %s\n\n", isEmpty(listNames), size(listNames), (char*)getTop(listNames));
	foreach(char, name, listNames)
		printf("%s\n", name);
		
	char* name = pop(listNames);
	printf("One name in list: %s\n", name);
	free(name);
	
	printf("(2) isEmpty: %d, size: %d\n\n", isEmpty(listNames), size(listNames));
	foreach(char, name, listNames)
		printf("%s\n", name);
	
	while((name = pop(listNames)) != NULL)
	{
		printf("Name deleted: %s\n", name);
		free(name);
	}

	printf("(3) isEmpty: %d, size: %d\n\n", isEmpty(listNames), size(listNames));
	push(listNames, "Lorenzo");
	push(listNames, "Victor");
	push(listNames, "Pepeito");
	
	printf("\nElement search: %s\n", (char*)find(listNames, "Victor", nameEquals));
	
	clear(listNames);
	
	foreach(char, name, listNames)
		printf("%s\n", name);
		
	delete(listNames);
	getchar();
    return 0;
}
