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

#include "lst/LinkedList.h"
#include "lst/MemoryManagement.h"
#include <stdlib.h>

void* newSL(size_t size, Compare compare)
{
	SortedList* sl = calloc(1, size);
	if(sl == NULL || addLastLK(&registers[LINKEDLIST], sl))
		return NULL;
	sl->compare = compare;
	return sl;
}

boolean insertOrder(LinkedList* lk, void* object)
{
	SortedList* sl = (SortedList*)lk;
	Node* newNode = createNode(lk, object, sizeof(Node));
	Node* aux;
	if(newNode == NULL)
		return true;
	if(lk->pBegin == NULL)
	{
		lk->pBegin = newNode;
		lk->pEnd = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else if(sl->compare(object, lk->pBegin->object) <= 0)
	{
		lk->pBegin->prev = newNode;
		newNode->next = lk->pBegin;
		lk->pBegin = newNode;
		newNode->prev = NULL;
	}
	else if(sl->compare(object, lk->pEnd->object) >= 0)
	{
		newNode->next = NULL;
		newNode->prev = lk->pEnd;
		lk->pEnd->next = newNode;
		lk->pEnd = newNode;
	}
	else
	{
		aux = lk->pBegin->next;
		while(1)
		{
			if(sl->compare(aux->object, object) >= 0)
			{
				aux->prev->next = newNode;
				newNode->prev = aux->prev;
				newNode->next = aux;
				aux->prev = newNode;
				break;
			}
			aux = aux->next;
		}
	}
	++lk->count;
	newNode->object = object;
	return false;
}

void* findSorted(LinkedList* lk, const void* key, const void* newElement, Equals equals)
{
	Node* aux = lk->pBegin;
	while(aux != NULL)
	{
		if(equals(aux->object, key))
		{
			if(lk->pBegin->next != NULL)
				searchPosition_Node(lk, newElement, aux);
			break;
		}
		aux = aux->next;
	}
	return (aux != NULL) ? (aux->object) : (NULL);
}

void searchPosition_Node(LinkedList* lk, const void* newElement, Node* updateNode)
{
	Node* aux;
	SortedList* sl = (SortedList*)lk;
	/* Si coincide con el primer nodo. */
	if(updateNode == lk->pBegin)
	{
		if(sl->compare(newElement, lk->pBegin->next->object) <= 0)
			return;
		if(sl->compare(newElement, lk->pEnd->object) >= 0)
		{
			lk->pBegin = lk->pBegin->next;
			lk->pBegin->prev = NULL;
			updateNode->next = NULL;
			updateNode->prev = lk->pEnd;
			lk->pEnd->next = updateNode;
			lk->pEnd = updateNode;
		}
		else
		{
			aux = lk->pBegin->next;
			while(1)
			{
				if(sl->compare(aux->object, newElement) >= 0)
				{
					lk->pBegin = lk->pBegin->next;
					lk->pBegin->prev = NULL;
					aux->prev->next = updateNode;
					updateNode->prev = aux->prev;
					updateNode->next = aux;
					aux->prev = updateNode;
					break;
				}
				aux = aux->next;
			}
		}
	}
	/* Si coincide con el último nodo. */
	else if(updateNode == lk->pEnd)
	{
		if(sl->compare(newElement, updateNode->prev->object) >= 0)
			return;
		if(sl->compare(newElement, lk->pBegin->object) <= 0)
		{
			lk->pEnd = updateNode->prev;
			lk->pEnd->next = NULL;
			updateNode->next = lk->pBegin;
			updateNode->prev = NULL;
			lk->pBegin->prev = updateNode;
			lk->pBegin = updateNode;
		}
		else 
		{
			aux = lk->pBegin;
			while(1)
			{
				if(sl->compare(aux->object, newElement) >= 0)
				{
					lk->pEnd = updateNode->prev;
					lk->pEnd->next = NULL;
					aux->prev->next = updateNode;
					updateNode->prev = aux->prev;
					updateNode->next = aux;
					aux->prev = updateNode;
					break;
				}
				aux = aux->next;
			}
		}
	}
	/* Si coincide con un nodo intermedio. */
	else if(sl->compare(newElement, updateNode->prev->object) < 0 || sl->compare(newElement, updateNode->next->object) > 0)
	{
		if(sl->compare(newElement, lk->pBegin->object) <= 0)
		{		
			updateNode->prev->next = updateNode->next;
			updateNode->next->prev = updateNode->prev;
			updateNode->next = lk->pBegin;
			updateNode->prev = NULL;
			lk->pBegin->prev = updateNode;
			lk->pBegin = updateNode;
		}
		else if(sl->compare(newElement, lk->pEnd->object) >= 0)
		{
			updateNode->prev->next = updateNode->next;
			updateNode->next->prev = updateNode->prev;
			updateNode->next = NULL;
			updateNode->prev = lk->pEnd;
			lk->pEnd->next = updateNode;
			lk->pEnd = updateNode;
		}
		else
		{
			aux = (sl->compare(newElement, updateNode->prev->object) < 0) ? (lk->pBegin) : (updateNode->next);
			while(1)
			{
				if(sl->compare(aux->object, newElement) >= 0)
				{
					updateNode->prev->next = updateNode->next;
					updateNode->next->prev = updateNode->prev;
					aux->prev->next = updateNode;
					updateNode->prev = aux->prev;
					updateNode->next = aux;
					aux->prev = updateNode;
					break;
				}
				aux = aux->next;
			}
		}
	}
}
