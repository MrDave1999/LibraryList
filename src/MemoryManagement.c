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
#include "lst/ArrayList.h"
#include "lst/LinkedList.h"
#include "lst/ArrayQueue.h"
#include "lst/ArrayStack.h"

LinkedList registers[MAX_LISTS];
boolean act = true;

void free_queue_stack(const ListType lt, void* objectList)
{
	if(lt == ARRAYQUEUE)
		free(((ArrayQueue*)objectList)->pArray);
	else if(lt == ARRAYSTACK)
		free(((ArrayStack*)objectList)->pArray);
}

void setContainer(boolean value)
{
	act = (value == 0 || value == 1) ? (value) : (true);
}

void* new_object_list(const ListType lt, size_t size)
{
	void* ptr = calloc(1, size);
	return (ptr == NULL || ADD_CONTAINER(&registers[lt], ptr)) ? NULL : ptr;
}

void delete_object_list(const ListType lt, void* objectList, Clear clear)
{
	clear(objectList);
	free_queue_stack(lt, objectList);
	act ? removeLK(&registers[lt], objectList, pointerEquals) : free(objectList);
}

boolean pointerEquals(const void* object, const void* key)
{
	return object == key;
}

void freeALL()
{
	freeALLEx(LINKEDLIST, (void(*)(void*))clearLK);
	freeALLEx(ARRAYLIST, (void(*)(void*))clearAL);
	freeALLEx(ARRAYQUEUE, (void(*)(void*))clearAQ);
}

void freeALLEx(const ListType lt, Clear clear)
{
	while (registers[lt].pBegin != NULL)
	{
		registers[lt].aux = registers[lt].pBegin;
		clear(registers[lt].pBegin->object);
		free_queue_stack(lt, registers[lt].pBegin->object);
		free(registers[lt].pBegin->object);
		registers[lt].pBegin = registers[lt].pBegin->next;
		free(registers[lt].aux);
	}
	registers[lt].count = 0;
}
