#include <stdlib.h>
//#include <stdio.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "MemoryManagement.h"

static LinkedList lk[2];

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
	//printf("CountLists: %d\n", lk[id].count);
}
