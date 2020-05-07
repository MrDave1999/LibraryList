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
#include "lst/ArrayList.h"
#include "lst/LinkedList.h"
#include "lst/Stack.h"

LinkedList registers[MAX_LISTS];

void* new_object_list(const size_t typeList, const size_t size)
{
	void* ptr = calloc(1, size);
	return (ptr == NULL || addLK(&registers[typeList], ptr)) ? NULL : ptr;
}

boolean equals(const void* object, const void* key)
{
	return object == key;
}

void delete_object_list(const size_t typeList, void* objectList, Clear clear)
{
	clear(objectList);
	removeLK(&registers[typeList], objectList, equals);
}

void freeALL()
{
	freeALLEx(LINKEDLIST, (void(*)(void*))clearLK);
	freeALLEx(ARRAYLIST, (void(*)(void*))clearAL);
	freeALLEx(STACK, (void(*)(void*))clear_stack);
}

void freeALLEx(const size_t typeList, Clear clear)
{
	while (registers[typeList].pBegin != NULL)
	{
		registers[typeList].aux = registers[typeList].pBegin;
		clear(registers[typeList].pBegin->object);
		free(registers[typeList].pBegin->object);
		registers[typeList].pBegin = registers[typeList].pBegin->sig;
		free(registers[typeList].aux);
	}
	registers[typeList].count = 0;
}
