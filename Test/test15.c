#include <stdio.h>
#include <stdlib.h> 
#include <lst/List.h>

int main()
{
	LinkedList* listNames = newLinkedList();
	
	push(listNames, "David");
	push(listNames, "Roberto");
	push(listNames, "Joel");
	push(listNames, "Josias");
	printf("(1) isEmpty: %d, size: %d, Front element: %s\n\n", isEmpty(listNames), size(listNames), (char*)getFront(listNames));
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
	
	enqueue(listNames, "Roberto Placencio");
	enqueue(listNames, "David");
	push(listNames, "Memo");
	
	foreach(char, name, listNames)
		printf("%s\n", name);
	
	clear(listNames);
	
	foreach(char, name, listNames)
		printf("%s\n", name);
		
	delete(listNames);
	getchar();
    return 0;
}
