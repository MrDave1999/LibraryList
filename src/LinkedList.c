#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

void clearLK(LinkedList* lk)
{
	Node* aux;
	if (lk->count != 0)
	{
		while (lk->pBegin != NULL)
		{
			aux = lk->pBegin;
			free(lk->pBegin->object);
			lk->pBegin = lk->pBegin->sig;
			free(aux);
		}
		lk->count = 0;
		lk->pEnd = NULL;
	}
}

void* getLK(LinkedList* lk, size_t index)
{
	size_t i = 0;
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (i++ == index)
			return lk->aux->object;
		lk->aux = lk->aux->sig;
	}
	return NULL;
}

void* setLK(LinkedList* lk, size_t index, void* newObject)
{
	return (getLK(lk, index) != NULL) ? (lk->aux->object = newObject) : (NULL);
}

uint8_t addLK(LinkedList* lk, void* object)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		free(object);
		freeALL();
		return EXIT_FAILURE;
	}
	++lk->count;
	(lk->pBegin == NULL) ? (lk->pBegin = newNode) : (lk->pEnd->sig = newNode);
	newNode->sig = NULL;
	newNode->object = object;
	lk->pEnd = newNode;
	return EXIT_SUCCESS;
}

uint8_t removeLK(LinkedList* lk, int(*funcComparator)(void*), const uint8_t option)
{
	uint8_t isExist = 1;
	Node* penNode = lk->pBegin;
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (funcComparator(lk->aux->object))
		{
			removeElement(lk, penNode);
			isExist = 0;
			if (option && !isExist)
				break;
			else continue;
		}
		penNode = lk->aux;
		lk->aux = lk->aux->sig;
	}
	return isExist;
}

uint8_t iremoveLK(LinkedList* lk, size_t index)
{
	size_t i = 0;
	Node* penNode = lk->pBegin;
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (i++ == index)
		{
			removeElement(lk, penNode);
			return 0;
		}
		penNode = lk->aux;
		lk->aux = lk->aux->sig;
	}
	return 1;
}

void removeElement(LinkedList* lk, Node* penNode)
{
	Node* aux2 = lk->aux;
	if (lk->pBegin->sig == NULL)
	{
		lk->pBegin = NULL;
		lk->pEnd = NULL;
	}
	else if (lk->pBegin == lk->aux)
		lk->pBegin = lk->pBegin->sig;
	else if (lk->pEnd == lk->aux)
	{
		penNode->sig = NULL;
		lk->pEnd = penNode;
	}
	else
		penNode->sig = lk->aux->sig;
	lk->aux = lk->aux->sig;
	free(aux2);
	--lk->count;
}

void* findLK(LinkedList* lk, int(*funcComparator)(void*))
{
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (funcComparator(lk->aux->object))
			return lk->aux->object;
		lk->aux = lk->aux->sig;
	}
	return NULL;
}
