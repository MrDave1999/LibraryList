#include <stdio.h>
#include <stdlib.h> 
#include <lst/List.h>
#include <string.h>

boolean nameEquals(const void* o1, const void* o2)
{
	return strcmp(o1, o2) == 0;
}

boolean numberEquals(const void* o1, const void* o2)
{
	return *(int*)o1 == *(int*)o2;
}

int main()
{ 
	ArrayList* list = newArrayList();
	setCapacity(list, 4);
	add(list, "David");
	add(list, "Jose");
	add(list, "Roberto");
	add(list, "Guillermo");
	
	foreach(char, name, list)
		printf("%s\n", name);
	
	char* prevName = set(list, 1, "Maria");
	printf("Previous name: %s\n", prevName);
	printf("Get(1): %s, size: %d\n", (char*)get(list, 1), size(list));
	free(prevName);
	
	oremove(list, "Roberto", nameEquals);
	printf("oremove: %d\n", oremove(list, "Memo", nameEquals));
	
	foreach(char, name, list)
		printf("%s\n", name);
		
	iremove(list, 2);
	
	foreach(char, name, list)
		printf("%s\n", name);
		
	if(find(list, "Maria", nameEquals) != NULL)
		printf("Maria si esta en la lista!\n");
	
	printf("size: %d\n", size(list));
	
	clear(list);
	
	add(list, 23);
	add(list, 23);
	add(list, 23);
	add(list, 24);
	add(list, 25);
	int num;
	foreach(int, number, list)
		printf("Number: %d\n", *number);
	puts("");
	num = 23;
	removeAll(list, &num, numberEquals);
	
	foreach(int, number, list)
		printf("Number: %d\n", *number);
	puts("");
	num = 24;
	removeAll(list, &num, numberEquals);
	num = 25;
	removeAll(list, &num, numberEquals);

	foreach(int, number, list)
		printf("Number: %d\n", *number);
	
	delete(list);
	getchar();
    return 0;
}
