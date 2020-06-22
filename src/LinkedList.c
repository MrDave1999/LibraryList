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

void* createNode(void* ptr, void* object, size_t size)
{
	void* newNode;
	if(ptr == NULL || object == NULL)
	{
		free(object);
		return NULL;
	}
	newNode = malloc(size);
	if (newNode == NULL)
	{
		free(object);
		return NULL;
	}
	return newNode;
}

boolean addLastLK(LinkedList* lk, void* object)
{
	Node* newNode = createNode(lk, object, sizeof(Node));
	if(newNode == NULL)
		return true;
	if(lk->pBegin == NULL)
	{
		lk->pBegin = newNode;
		newNode->prev = NULL;
	}
	else
	{
		lk->pEnd->next = newNode;
		newNode->prev = lk->pEnd;
	}
	newNode->next = NULL;
	lk->pEnd = newNode;
	newNode->object = object;
	++lk->count;
	return false;
}

boolean addFirstLK(LinkedList* lk, void* object)
{
	Node* newNode = createNode(lk, object, sizeof(Node));
	if(newNode == NULL)
		return true;
	(lk->pBegin == NULL) ? (lk->pEnd = newNode) : (lk->pBegin->prev = newNode);
	newNode->next = lk->pBegin;
	newNode->prev = NULL;
	lk->pBegin = newNode;
	newNode->object = object;
	++lk->count;
	return false;
}

boolean addLK_Index(LinkedList* lk, const int index, void* object)
{
	Node* newNode, *aux;
	int i;
	newNode = createNode(lk, object, sizeof(Node));
	if(newNode == NULL)
		return true;
	i = 0;
	aux = lk->pBegin;
	while(i++ != index)
		aux = aux->next;
	if(lk->pBegin == aux)
	{
		lk->pBegin = newNode;
		newNode->prev = NULL;
	}
	else
	{
		aux->prev->next = newNode;
		newNode->prev = aux->prev;
	}
	newNode->next = aux;
	aux->prev = newNode;
	newNode->object = object;
	++lk->count;
	return false;
}

void* getLK(LinkedList* lk, const int index)
{
	int i;
	if(isRange(lk, index))
		return NULL;
	i = 0;
	lk->aux = lk->pBegin;
	while(i++ != index)
		lk->aux = lk->aux->next;
	return lk->aux->object;
}

void* setLK(LinkedList* lk, const int index, void* newObject)
{
	void* prevObject = NULL;
	if(newObject != NULL)
	{
		prevObject = getLK(lk, index);
		lk->aux->object = newObject;
	}
	return prevObject;
}

void* removeFirstLK(LinkedList* lk)
{
	Node* aux;
	void* ob;
	if(lk->pBegin == NULL)
		return NULL;
	aux = lk->pBegin;
	ob = aux->object;
	--lk->count;
	lk->pBegin = lk->pBegin->next;
	if(lk->pBegin != NULL)
		lk->pBegin->prev = NULL;
	free(aux);
	return ob;
}

boolean removeLK(LinkedList* lk, const void* key, Equals equals)
{
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (equals(lk->aux->object, key))
		{
			removeNode(lk);
			return false;
		}
		lk->aux = lk->aux->next;
	}
	return true;
}

boolean removeAll_LK(LinkedList* lk, const void* key, Equals equals)
{
	boolean isExist = true;
	lk->aux = lk->pBegin;
	while (lk->aux != NULL)
	{
		if (equals(lk->aux->object, key))
		{
			removeNode(lk);
			isExist = false;
			continue;
		}
		lk->aux = lk->aux->next;
	}
	return isExist;
}

boolean iremoveLK(LinkedList* lk, const int index)
{
	int i;
	if(isRange(lk, index))
		return true;
	i = 0;
	lk->aux = lk->pBegin;
	while(i++ != index)
		lk->aux = lk->aux->next;
	removeNode(lk);
	return false;
}
           
void removeNode(LinkedList* lk)
{
	Node* aux2 = lk->aux;
	if (lk->pBegin->next == NULL)
	{
		lk->pBegin = NULL;
		lk->pEnd = NULL;
	}
	else if (lk->pBegin == lk->aux)
	{
		lk->pBegin = lk->pBegin->next;
		lk->pBegin->prev = NULL;
	}
	else if (lk->pEnd == lk->aux)
	{
		lk->aux->prev->next = NULL;
		lk->pEnd = lk->aux->prev;
	}
	else
	{  
		lk->aux->prev->next = lk->aux->next;
		lk->aux->next->prev = lk->aux->prev;
	}
	lk->aux = lk->aux->next;
	free(aux2->object);
	free(aux2);
	--lk->count;
}

void clearLK(LinkedList* lk)
{
	Node* aux;
	while (lk->pBegin != NULL)
	{
		aux = lk->pBegin;
		free(lk->pBegin->object);
		lk->pBegin = lk->pBegin->next;
		free(aux);
	}
	lk->count = 0;
}

void* findLK(LinkedList* lk, const void* key, Equals equals)
{
	Node* aux = lk->pBegin;
	while (aux != NULL)
	{
		if (equals(aux->object, key))
			return aux->object;
		aux = aux->next;
	}
	return NULL;
}

int sizeLK(LinkedList* lk)
{
	return lk->count;
}

boolean isEmptyLK(LinkedList* lk)
{
	return lk->pBegin == NULL;
}

void* minLK(LinkedList* lk, Compare compare)
{
	void* candidate;
	Node* aux;
	if(lk->count == 0)
		return NULL;
	candidate = lk->pBegin->object;
	aux = lk->pBegin->next;
	while(aux != NULL)
	{
		if(compare(aux->object, candidate) < 0)
			candidate = aux->object;
		aux = aux->next;
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
	aux = lk->pBegin->next;
	while(aux != NULL)
	{
		if(compare(aux->object, candidate) > 0)
			candidate = aux->object;
		aux = aux->next;
	}
	return candidate;
}
