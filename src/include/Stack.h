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

#ifndef _STACK_H
#define _STACK_H

#include "LinkedList.h"

struct Stack
{
	size_t i;
	size_t count;
	struct Node* pTop;
	struct Node* aux;
};

typedef struct Stack Stack;

#define push(expr, obj) push_(expr, addDTP(obj))
#define newStack() new_object_list(STACK, sizeof(Stack))
#define delete_stack(objectStack) delete_object_list(STACK, objectStack, (void(*)(void*))clear_stack)

boolean push_(Stack*, void*);
void* pop(Stack*);
void* getTop(Stack*);
size_t size_stack(Stack*);
boolean isEmpty_stack(Stack*);
void clear_stack(Stack*);

#endif /* _STACK_H */
