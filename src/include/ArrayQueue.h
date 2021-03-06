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

#ifndef _ARRAYQUEUE_H
#define _ARRAYQUEUE_H

#include "def.h"

struct ArrayQueue
{
	void** pArray;
	int i; /* para contar las iteraciones. */
	int count; /* cantidad actual de elementos. */
	int max; /* tamaño máximo del array. */
	int begin; /* posición inicial. */
	int n; /* para recorrer el array. */
};

typedef struct ArrayQueue ArrayQueue;
#define deleteAQ(objectAQ) delete_object(ARRAYQUEUE, objectAQ, (void(*)(void*))clearARRAYQUEUE)
#define newArrayQueue(max) createArray(max, sizeof(ArrayQueue), ARRAYQUEUE)

void* createArray(int, size_t, TypeStructs);
boolean addLastAQ(ArrayQueue*, void*);
void* removeFirstAQ(ArrayQueue*);
void* getFrontAQ(ArrayQueue*);
boolean fullAQ(ArrayQueue*);
boolean isEmptyAQ(ArrayQueue*);
int sizeAQ(ArrayQueue*);
void clearARRAYQUEUE(ArrayQueue*);
void* findAQ(ArrayQueue*, const void*, Equals);

#endif /* _ARRAYQUEUE_H */
