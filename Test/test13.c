#include <stdio.h>
#include <lst/List.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int edad;
	const char* nombre;
	const char* apellido;
}Persona;

int OrdenarPorEdad(const void* o1, const void* o2)
{
	return *(int*)o1 - *(int*)o2;
}

boolean EncontrarPersona(const void* p, const void* key)
{
	return strcmp(((Persona*)p)->nombre, key) == 0;
}

Persona* crearPersona(int edad, const char* nombre, const char* apellido)
{
	Persona* per = malloc(sizeof(Persona));
	if(per != NULL)
	{
		per->edad = edad;
		per->nombre = nombre;
		per->apellido = apellido;
	}
	return per;
}

int main()
{
	char nombre[24];
	int edad;
	Persona* perSearch;
	LinkedList* listaPersona = newSortedList(OrdenarPorEdad);
	
	addSorted(listaPersona, crearPersona(18, "David", "Roman"));
	addSorted(listaPersona, crearPersona(16, "Jose", "Perez"));
	addSorted(listaPersona, crearPersona(20, "Maria", "Consuelo"));
	addSorted(listaPersona, crearPersona(15, "Memo", "Lopez"));
	addSorted(listaPersona, crearPersona(18, "Josue", "Roman"));
	addSorted(listaPersona, crearPersona(18, "Dario", "Roman"));
	addSorted(listaPersona, crearPersona(16, "Pepe", "Tola"));

	foreach(Persona, per, listaPersona)
		printf("Nombre: %s, Apellido: %s, Edad: %d\n", per->nombre, per->apellido, per->edad);
	
	printf("Ingrese un nombre: ");
	scanf("%s", nombre);
	
	printf("\nIngrese un nueva edad: ");
	scanf("%d", &edad);
	
	if((perSearch = findSorted(listaPersona, nombre, &edad, EncontrarPersona)) == NULL)
		printf("Esa persona no se encuentra en la lista\n");
	else
	{
		perSearch->edad = edad;
		foreach(Persona, per, listaPersona)
			printf("Nombre: %s, Apellido: %s, Edad: %d\n", per->nombre, per->apellido, per->edad);
	}
	delete(listaPersona);
    return 0;
}
