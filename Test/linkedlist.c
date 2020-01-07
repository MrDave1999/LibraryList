#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "LinkedList.h"

#ifndef __DEBUG
#define addAL addLK
#define ArrayList LinkedList
#define forAL forLK
#define removeAL removeLK
#define iremoveAL iremoveLK
#define setAL setLK
#define getAL getLK
#define findAL findLK
#define newArrayList newLinkedList
#endif

typedef struct
{
	int edad;
	int altura;
	int cod;
}Persona;


int edad;
int compare(void* p)
{
	return ((Persona*)p)->edad == edad;
}

int compareCod(void* p)
{
	return ((Persona*)p)->cod == 10;
}

void act(ArrayList* listaPersonas)
{
	printf("Objects: %d\n\n", listaPersonas->count);
	forAL(Persona, per, listaPersonas)
		printf("%d, %d, %d\n", per->altura, per->cod, per->edad);
}

int main(void)
{
	int cod = 0;
	srand((unsigned int)time(NULL));
	ArrayList* listaPersonas = newArrayList();
	//Añadimos los objetos.
	for (int i = 0; i != 20; ++i)
	{
		Persona* per = newObject(Persona);
		
		if (addAL(listaPersonas, per))
			return 1;
		per->edad = rand() % 100;
		if (cod < 5)
			per->edad = 10;
		per->altura = rand() % 100;
		per->cod = ++cod;
	}
	act(listaPersonas);
	iremoveAL(listaPersonas, 5);
	iremoveAL(listaPersonas, 0);
	iremoveAL(listaPersonas, 17);
	act(listaPersonas);

	edad = 10;
	removeAL(listaPersonas, compare, ONE);
	removeAL(listaPersonas, compare, ALL);
	act(listaPersonas);
	Persona* per;
	if ((per = findAL(listaPersonas, compareCod)) != NULL)
		printf("\nInfo: %d, %d, %d\n", per->altura, per->cod, per->edad);

	Persona* aux;
	per = getAL(listaPersonas, 2);
	printf("%d\n", per->cod);
	per = newObject(Persona);
	if (per == NULL) return 1;
	aux = getAL(listaPersonas, 2);
	per->cod = 1000;
	setAL(listaPersonas, 2, per);
	free(aux);
	printf("%d\n", per->cod);
	freeALL();
	return 0;
}
