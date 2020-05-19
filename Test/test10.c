#include <stdio.h>
#include <lst/List.h>

void showInfo(LinkedList* list)
{
	printf("\n\n---> List Name:\n");
	foreach(char, name, list)
		printf("%s\n", name);
}

int main()
{
	LinkedList* list = newLinkedList();
	add(list, "Pepito");
	add(list, "Joseito");
	add(list, "Perez");
	add(list, "Koko");
	add(list, "David");
	add(list, "Memo");
	
	iremove(list, 0);
	showInfo(list);
	iremove(list, 4);
	showInfo(list);
	iremove(list, 1);
	showInfo(list);
	
	iremove(list, 2);
	showInfo(list);
	iremove(list, 1);
	showInfo(list);
	iremove(list, 0);
	showInfo(list);
	
	getchar();
    return 0;
}
