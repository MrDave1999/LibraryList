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

#ifndef _MEMORYMANAGEMENT_H
#define _MEMORYMANAGEMENT_H

#include <stdint.h>

#define clears freeALL
#define MAX_LISTS	(3)
#define true 1
#define false 0

enum
{
	QUEUE,
	LINKEDLIST = 0,
	ARRAYLIST,
	STACK
};

typedef unsigned char boolean;
typedef void(*Clear)(void*);
typedef boolean(*Equals)(const void*, const void*);
typedef int(*Compare)(const void*, const void*);

void* new_object_list(const size_t, const size_t);
void delete_object_list(const size_t, void*, Clear clear);
void freeALLEx(const size_t, Clear clear);
void freeALL(void);

#endif /* _MEMORYMANAGEMENT_H */
