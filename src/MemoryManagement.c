#include <stdlib.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "MemoryManagement.h"

static LinkedList lk[2];
static void* searchObject;

void* __new__(size_t id, size_t size)
{
	void* ptr = calloc(1, size);
	if (ptr == NULL || addLK(&lk[id], ptr))
	{
		freeALL();
		return NULL;
	}
	return ptr;
}

void* __newObject__(size_t size)
{
	void* p = malloc(size);
	if (p == NULL)
	{
		freeALL();
		return NULL;
	}
	return p;
}

int compare(void* object)
{
	return object == searchObject;
}

void freeObject(size_t id, void* objectList, void(*clear)(void*))
{
	searchObject = objectList;
	clear(objectList);
	removeLK(&lk[id], compare, ALL);
}

void freeALL()
{
	freeALLEx(LINKEDLIST, clearLK);
	freeALLEx(ARRAYLIST, clearAL);
}

void freeALLEx(size_t id, void(*clear)(void*))
{
	while (lk[id].pBegin != NULL)
	{
		lk[id].aux = lk[id].pBegin;
		clear(lk[id].pBegin->object);
		free(lk[id].pBegin->object);
		lk[id].pBegin = lk[id].pBegin->sig;
		free(lk[id].aux);
	}
	lk[id].count = 0;
}
