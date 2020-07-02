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

#include "lst/algorithm.h"

static void** arrayElement;
static Compare cmp;

void quicksort(int first, int end)
{
	int i, j;
	void* pivote = arrayElement[(first + end) / 2];
	i = first;
	j = end;
	do
	{
		while(cmp(arrayElement[i], pivote) < 0) ++i;
		while(cmp(arrayElement[j], pivote) > 0) --j;
		if (i <= j)
		{
			swapElement(arrayElement[i], arrayElement[j]);
			++i;
			--j;
		}
	} while (i <= j);
	/* Para ordenar los elementos de la subarray izquierdo. */
	if (first < j)
		quicksort(first, j);
	/* Para ordenar los elementos de la subarray derecho. */
	if (i < end)
		quicksort(i, end);
}

boolean invoke_quicksort(ArrayList* al, Compare compare)
{
	if(al->count == 0)
		return true;
	if(al->count == 1)
		return false;
	arrayElement = al->pArray;
	cmp = compare;
	quicksort(0, al->count - 1);
	return false;
}

void mergesort(Node** pBegin, Node** pEnd, int length)
{
	List sublistLeft, sublistRight;
	if((*pBegin)->next == NULL)
		return;
	splitList(*pBegin, *pEnd, length, &sublistLeft, &sublistRight);
	mergesort(&sublistLeft.first, &sublistLeft.end, sublistLeft.length);
	mergesort(&sublistRight.first, &sublistRight.end, sublistRight.length);
	merge(pBegin, pEnd, &sublistLeft, &sublistRight);
}

void splitList(Node* pBegin, Node* pEnd, int length, List* sublistLeft, List* sublistRight)
{
	int i = 1;
	int medium = length / 2;
	Node* aux = pBegin;
	/* Recorremos hasta encontrar el nodo medio. */
	while(i++ < medium) 
		aux = aux->next;
	sublistLeft->first = pBegin;
	sublistLeft->end = aux;
	sublistRight->first = aux->next;
	sublistRight->end = pEnd;
	aux->next->prev = NULL;
	aux->next = NULL;
	sublistLeft->length = medium;
	sublistRight->length = length - medium;
}

void merge(Node** pBegin, Node** pEnd, List* sublistLeft, List* sublistRight)
{ 
	/* Almacena la dirección de memoria del campo siguiente del último nodo de la lista combinada. */
	Node** last_campusNext = pBegin;
	/* Almacena la dirección base del último nodo de la lista combinada. */
	Node* lastNode = NULL;
	/* Actualizamos el puntero donde se guardará la dirección del primer nodo de la lista combinada. */
	*pBegin = NULL;
	while(1)
	{
		if(sublistLeft->first == NULL)
		{
			sublistRight->first->prev = lastNode;
			*last_campusNext = sublistRight->first;
			break;
		}
		if(sublistRight->first == NULL)
		{
			sublistLeft->first->prev = lastNode;
			*last_campusNext = sublistLeft->first;
			break;
		}
		if(cmp(sublistLeft->first->object, sublistRight->first->object) <= 0)
		{
			moveNode(last_campusNext, sublistLeft->first);
		}
		else
		{
			moveNode(last_campusNext, sublistRight->first);
		}
		last_campusNext = &(*last_campusNext)->next;
	}
	/* Actualizamos el puntero donde se guardará la dirección del último nodo de la lista combinada. */
	*pEnd = (sublistLeft->end->next == NULL) ? (sublistLeft->end) : (sublistRight->end);
}

boolean invoke_mergesort(LinkedList* lk, Compare compare)
{
	if(lk->count == 0)
		return true;
	if(lk->count == 1)
		return false;
	cmp = compare;
	mergesort(&lk->pBegin, &lk->pEnd, lk->count);
	return false;
}

boolean bsortLK(LinkedList* lk, Compare compare)
{
	Node* aux;
	Node* pEnd = lk->pEnd;
	boolean change = false;
	if(lk->count == 0)
		return true;
	while(1)
	{
		aux = lk->pBegin;
		while(aux != pEnd)
		{
			if(compare(aux->object, aux->next->object) > 0)
			{			
				swapElement(aux->next->object, aux->object);
				change = true;
			}	
			aux = aux->next;
		}
		if(!change) break;
		pEnd = pEnd->prev;
		change = false;
	}
	return false;
}

boolean bsortAL(ArrayList* al, Compare compare)
{
	int len = al->count;
	if(len == 0)
		return true;
	boolean change = false;
	while(1)
	{
		for(int i = 1; i != len; ++i)
		{
			if(compare(al->pArray[i - 1], al->pArray[i]) > 0)
			{		
				swapElement(al->pArray[i], al->pArray[i - 1]);
				change = true;
			}	
		}
		if(!change) break;
		--len;
		change = false;
	}
	return false;
}

void* bSearch(ArrayList* al, const void* key, Compare compare)
{
	return getAL(al, bSearch_i(al, key, compare));
}

int bSearch_i(ArrayList* al, const void* key, Compare compare)
{
	int cmp;
	int first = 0;
	int end = al->count - 1;
	int medium;
	while (first <= end)
	{
		medium = (first + end) / 2;
		cmp = compare(al->pArray[medium], key);
		if (cmp == 0)
			return medium;
		(cmp < 0) ? (first = medium + 1) : (end = medium - 1);
	}
	return -1;
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

void* minAL(ArrayList* al, Compare compare)
{
	void* candidate;
	if(al->count == 0)
		return NULL;
	candidate = al->pArray[0];
	for(int i = 1; i != al->count; ++i)
	{
		if(compare(al->pArray[i], candidate) < 0)
			candidate = al->pArray[i];
	}
	return candidate;
}

boolean reverseLK(LinkedList* lk)
{
	Node* begin, *end;
	if(lk->count == 0)
		return true;
	begin = lk->pBegin;
	end = lk->pEnd;
	for(int i = 0, j = lk->count; i < --j; ++i)
	{
		swapElement(begin->object, end->object);
		begin = begin->next;
		end = end->prev;
	}
	return false;
}

boolean reverseAL(ArrayList* al)
{
	if(al->count == 0)
		return true;
	for(int i = 0, j = al->count; i < --j; ++i)
	{
		swapElement(al->pArray[i], al->pArray[j]);
	}
	return false;
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

void* maxAL(ArrayList* al, Compare compare)
{
	void* candidate;
	if(al->count == 0)
		return NULL;
	candidate = al->pArray[0];
	for(int i = 1; i != al->count; ++i)
	{
		if(compare(al->pArray[i], candidate) > 0)
			candidate = al->pArray[i];
	}
	return candidate;
}
