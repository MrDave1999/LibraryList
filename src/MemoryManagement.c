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
#include "lst/LinkedList.h"
#include "lst/ArrayQueue.h"

#define ADD_CONTAINER(list, ob) (act && addLastLK(list, ob))

#define FREE_ARRAY(p) \
	if(ts == ARRAYQUEUE || ts == ARRAYSTACK) \
		free(((ArrayQueue*)p)->pArray);

static LinkedList registers[MAX_STRUCTS];
static boolean act = true;

int getCountStructs(TypeStructs ts)
{
	return registers[ts].count;
}

void disableFA()
{
	act = false;
}

boolean pointerEquals(const void* object, const void* key)
{
	return object == key;
}

void* new_object(TypeStructs ts, size_t size)
{
	void* ptr = calloc(1, size);
	return (ptr == NULL || ADD_CONTAINER(&registers[ts], ptr)) ? NULL : ptr;
}

void delete_object(TypeStructs ts, void* po, Clear clear)
{
	clear(po);
	FREE_ARRAY(po);
	act ? removeLK(&registers[ts], po, pointerEquals) : free(po);
}

void freeALL(TypeStructs ts, Clear clear)
{
	while (registers[ts].pBegin != NULL)
	{
		registers[ts].aux = registers[ts].pBegin;
		clear(registers[ts].pBegin->object);
		FREE_ARRAY(registers[ts].pBegin->object);
		free(registers[ts].pBegin->object);
		registers[ts].pBegin = registers[ts].pBegin->next;
		free(registers[ts].aux);
	}
	registers[ts].count = 0;
}
