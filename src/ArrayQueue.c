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
#include "lst/MemoryManagement.h"
#include "lst/ArrayQueue.h"
#include "lst/ArrayStack.h"

void* createArray(int max, size_t size, ListType lt)
{
	void* ptr;
	void** pArray = malloc(max * sizeof(void*));
	if(pArray == NULL)
		return NULL;
	ptr = calloc(1, size);
	if(ptr == NULL || ADD_CONTAINER(&registers[lt], ptr))
	{
		free(pArray);
		return NULL;
	}
	if(lt == ARRAYSTACK)
		((ArrayStack*)ptr)->top = max;
	((ArrayQueue*)ptr)->max = max;
	((ArrayQueue*)ptr)->pArray = pArray;
	return ptr;
}

boolean addLastAQ(ArrayQueue* qe, void* object)
{
	int newPos;
	if(qe->count == qe->max)
		return true;
	newPos = (qe->begin + qe->count) % qe->max;
	qe->pArray[newPos] = object;
	++qe->count;
	qe->n = qe->begin + qe->count;
	return false;
}

void* removeFirstAQ(ArrayQueue* qe)
{
	void* oldObject = NULL;
	if(qe->count == 0)
		return NULL;
	oldObject = qe->pArray[qe->begin];
	qe->begin = (qe->begin + 1) % qe->max;
	--qe->count;
	qe->n = qe->begin + qe->count;
	return oldObject;
}

void* getFrontAQ(ArrayQueue* qe)
{
	return qe->pArray[qe->begin];
}

boolean fullAQ(ArrayQueue* qe)
{
	return qe->max == qe->count;
}

boolean isEmptyAQ(ArrayQueue* qe)
{
	return qe->count == 0;
}

int sizeAQ(ArrayQueue* qe)
{
	return qe->count;
}

void clearAQ(ArrayQueue* qe)
{
	for(int i = qe->begin; i < qe->n; ++i)
		free(qe->pArray[i % qe->max]);
	qe->count = 0;
	qe->begin = 0;
	qe->n = 0;
}

void* findAQ(ArrayQueue* qe, const void* key, Equals equals)
{
	for(int i = qe->begin; i < qe->n; ++i)
	{
		if (equals(qe->pArray[i % qe->max], key))
			return qe->pArray[i % qe->max];
	}
	return NULL;
}
