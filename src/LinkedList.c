/*
	Copyright (c) 2020 MrDave1999 (David Román)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include <stdlib.h>
#include <stdio.h>
#include "lst/LinkedList.h"
#include "lst/isRange.h"

boolean addLK(LinkedList* lk, void* object)
{
	Node* newNode;
	if(lk == NULL || object == NULL)
	{
		free(object);
		return EXIT_FAILURE;
	}
	newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		free(object);
		return EXIT_FAILURE;
	}
	++lk->count;
	(lk->pBegin == NULL) ? (lk->pBegin = newNode) : (lk->pEnd->sig = newNode);
	newNode->sig = NULL;
	newNode->object = object;
	lk->pEnd = newNode;
	return EXIT_SUCCESS;
}

boolean addLK_Index(LinkedList* lk, const size_t index, void* object)
{
	Node* newNode, *penNode;
	int i;
	if(lk == NULL || object == NULL)
	{
		free(object);
		return true;
	}
	newNode = malloc(sizeof(Node));
	if(newNode == NULL)
	{
		free(object);
		return true;
	}
	i = 0;
	penNode = NULL;
	lk->aux = lk->pBegin;
	while(i++ != index)
	{
		penNode = lk->aux;
		lk->aux = lk->aux->sig;
	}
	(lk->pBegin == lk->aux) ? (lk->pBegin = newNode) : (penNode->sig = newNode);
	newNode->sig = lk->aux;
	newNode->object = object;
	++lk->count;
	return false;
}

void* getLK(LinkedList* lk, const size_t index)
{
	size_t i;
	if(isRange(lk, index))
		return NULL;
	i = 0;
	lk->aux = lk->pBegin;
	while(i++ != index)
		lk->aux = lk->aux->sig;
	return lk->aux->object;
}

void* setLK(LinkedList* lk, const size_t index, void* newObject)
{
	void* prevObject = NULL;
	if(newObject != NULL)
	{
		prevObject = getLK(lk, index);
		lk->aux->object = newObject;
	}
	return prevObject;
}

boolean removeLK(LinkedList* lk, const void* key, Equals equals)
{
	Node* penNode = lk->pBegin;
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (equals(lk->aux->object, key))
		{
			removeElement(lk, penNode);
			return false;
		}
		penNode = lk->aux;
		lk->aux = lk->aux->sig;
	}
	return true;
}

boolean removeAll_LK(LinkedList* lk, const void* key, Equals equals)
{
	boolean isExist = true;
	Node* penNode = lk->pBegin;
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (equals(lk->aux->object, key))
		{
			removeElement(lk, penNode);
			isExist = false;
			continue;
		}
		penNode = lk->aux;
		lk->aux = lk->aux->sig;
	}
	return isExist;
}

boolean iremoveLK(LinkedList* lk, const size_t index)
{
	size_t i;
	Node* penNode;
	if(isRange(lk, index))
		return true;
	i = 0;
	penNode = NULL;
	lk->aux = lk->pBegin;
	while(i++ != index)
	{
		penNode = lk->aux;
		lk->aux = lk->aux->sig;
	}
	removeElement(lk, penNode);
	return false;
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
	free(aux2->object);
	free(aux2);
	--lk->count;
}

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
	}
}

void* findLK(LinkedList* lk, const void* key, Equals equals)
{
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (equals(lk->aux->object, key))
			return lk->aux->object;
		lk->aux = lk->aux->sig;
	}
	return NULL;
}

size_t sizeLK(LinkedList* lk)
{
	return lk->count;
}

boolean isEmptyLK(LinkedList* lk)
{
	return lk->pBegin == NULL;
}

void bsortLK(LinkedList* lk, Compare compare)
{
	Node* aux;
	void* p;
	Node* pEnd = lk->pEnd;
	Node* pPrev;//pPrevious
	boolean change = false;
	while(1)
	{
		aux = lk->pBegin;
		while(aux != pEnd)
		{
			if(compare(aux->object, aux->sig->object) > 0)
			{			
				p = aux->sig->object;
				aux->sig->object = aux->object;
				aux->object = p;
				change = true;
			}	
			pPrev = aux;
			aux = aux->sig;
		}
		if(!change) break;
		pEnd = pPrev;
		change = false;
	}
}

void* minLK(LinkedList* lk, Compare compare)
{
	void* candidate;
	Node* aux;
	if(lk->count == 0)
		return NULL;
	candidate = lk->pBegin->object;
	aux = lk->pBegin->sig;
	while(aux != NULL)
	{
		if(compare(aux->object, candidate) < 0)
			candidate = aux->object;
		aux = aux->sig;
	}
	return candidate;
}

void* maxLK(LinkedList* lk, Compare compare)
{
	void* candidate;
	Node* aux;
	if(lk->count == 0)
		return NULL;
	candidate = lk->pBegin->object;
	aux = lk->pBegin->sig;
	while(aux != NULL)
	{
		if(compare(aux->object, candidate) > 0)
			candidate = aux->object;
		aux = aux->sig;
	}
	return candidate;
}
