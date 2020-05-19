#include <stdio.h>
#include <stdlib.h>
#include <lst/List.h>

int main()
{
	int pos;
	LinkedList* list1 = newLinkedList();
	add(list1, 2);
	add(list1, 12);
	add(list1, 22);
	add(list1, 222);
	
	printf("Ingrese una posicion (list1):\n");
	scanf("%d", &pos);
	
	if(isRange(list1, pos))
	{
		printf("Error: La posicion debe estar en el rango de 0 a %d\n", size(list1)-1);
		return 1;
	}
	
	int* value = set(list1, pos, 2000);
	if(value == NULL)
	{
		printf("Error: No se pude reservar memoria para el nuevo objeto\n");
		return 1;
	}
	printf("El valor anterior que estaba en la posicion %d es %d\n", pos, *value);
	printf("Valor actual: %d\n", *(int*)get(list1, pos));
	free(value);
	delete(list1);
	
	getchar();
    return 0;
}
