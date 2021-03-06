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

#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include "def.h"

struct ArrayStack
{
	void** pArray;
	int i; 
	int count;
	int max;
};

typedef struct ArrayStack ArrayStack;
#define deleteAS(objectAS) delete_object(ARRAYSTACK, objectAS, (void(*)(void*))clearARRAYSTACK)
#define newArrayStack(max) createArray(max, sizeof(ArrayStack), ARRAYSTACK)

boolean addFirstAS(ArrayStack*, void*);
void* removeFirstAS(ArrayStack*);
void* getTopAS(ArrayStack*);
boolean fullAS(ArrayStack*);
boolean isEmptyAS(ArrayStack*);
int sizeAS(ArrayStack*);
void clearARRAYSTACK(ArrayStack*);
void* findAS(ArrayStack*, const void*, Equals);

#endif /* _ARRAYSTACK_H */
