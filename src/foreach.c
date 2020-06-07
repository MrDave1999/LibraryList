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
#include "lst/ArrayList.h"
#include "lst/ArrayQueue.h"
#include "lst/ArrayStack.h"

void setDefaultAL(ArrayList* al)
{
	al->i = 0;
}

void setDefaultLK(LinkedList* lk)
{
	lk->aux = lk->pBegin;
}

void setDefaultAQ(ArrayQueue* qe)
{
	qe->i = qe->begin;
}

void setDefaultAS(ArrayStack* as)
{
	as->i = as->top;
}

boolean hasNextAL(ArrayList* al)
{
	return al->i < al->count;
}

boolean hasNextLK(LinkedList* lk)
{
	return lk->aux != NULL;
}

boolean hasNextAQ(ArrayQueue* qe)
{
	return qe->i < qe->n;
}

boolean hasNextAS(ArrayStack* as)
{
	return as->i < as->max;
}

void* getNextAL(ArrayList* al)
{
	return al->pArray[al->i++];
}

void* getNextLK(LinkedList* lk)
{
	void* aux = lk->aux->object;
	lk->aux = lk->aux->next;
	return aux;
}

void* getNextAQ(ArrayQueue* qe)
{
	return qe->pArray[qe->i++ % qe->max];
}

void removeElement_AL(ArrayList* al)
{
	iremoveAL(al, --al->i);
}

void removeElement_LK(LinkedList* lk)
{
	lk->aux = (lk->pBegin->next == NULL) ? (lk->pBegin) : //Si solo hay un nodo en la lista..
		(lk->aux == NULL) ? (lk->pEnd) //Si estamos en el último nodo..
		: (lk->aux->prev); //De lo contrario, estamos en un nodo intermedio..
	removeNode(lk);
}
