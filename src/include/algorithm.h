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

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "LinkedList.h"
#include "ArrayList.h"

struct List
{
	Node* first;
	Node* end;
	int length;
};

typedef struct List List;

/* Mueve un nodo hacia el último nodo de la lista combinada. */
#define moveNode(last, first) \
	first->prev = lastNode; \
	*last = first; \
	lastNode = first; \
	first = first->next

/* Intercambia los contenidos ambos punteros. */
#define swapElement(element1, element2)  \
	void* aux_e = element1; \
	element1 = element2; \
	element2 = aux_e 

void quicksort(int, int);
boolean invoke_quicksort(ArrayList*, Compare);
void mergesort(Node**, Node**, int);
void splitList(Node*, Node*, int, List*, List*);
void merge(Node**, Node**, List*, List*);
boolean invoke_mergesort(LinkedList*, Compare);
boolean bsortLK(LinkedList*, Compare);
boolean bsortAL(ArrayList*, Compare);
void* bSearch(ArrayList*, const void*, Compare);
int bSearch_i(ArrayList*, const void*, Compare);
void* maxLK(LinkedList*, Compare);
void* maxAL(ArrayList*, Compare);
boolean reverseLK(LinkedList*);
boolean reverseAL(ArrayList*);
void* minLK(LinkedList*, Compare);
void* minAL(ArrayList*, Compare);

#endif /* _ALGORITHM_H */
