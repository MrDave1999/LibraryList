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

void* getElementDefaultAL(ArrayList* al)
{
	al->i = 0;
	return (al->count == 0) ? (NULL) : (al->pArray[al->i]);
}

void* getElementDefaultLK(LinkedList* lk)
{
	lk->aux = lk->pBegin;
	return (lk->count == 0) ? (NULL) : (lk->aux->object);
}

void* getElementDefaultAQ(ArrayQueue* qe)
{
	qe->i = qe->begin;
	return qe->pArray[qe->i];
}

void* getElementDefaultAS(ArrayStack* as)
{
	as->i = as->top;
	return as->pArray[as->i];
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

void* getNextElementAL(ArrayList* al)
{
	return (++al->i < al->count) ? (al->pArray[al->i]) : (NULL);
}

void* getNextElementLK(LinkedList* lk)
{
	lk->aux = lk->aux->next;
	return (lk->aux != NULL) ? (lk->aux->object) : (NULL);
}

void* getNextElementAQ(ArrayQueue* qe)
{
	return (++qe->i < qe->n) ? (qe->pArray[qe->i % qe->max]) : (NULL);
}

void* getNextElementAS(ArrayStack* as)
{
	return (++as->i < as->max) ? (as->pArray[as->i]) : (NULL);
}
