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
#include "lst/ArrayStack.h"

boolean addFirstAS(ArrayStack* as, void* object)
{
	if(as == NULL || object == NULL)
	{
		free(object);
		return true;
	}
	as->pArray[as->count++] = object;
	return false;
}

void* removeFirstAS(ArrayStack* as)
{
	if(as->count == 0)
		return NULL;
	return as->pArray[--as->count];
}

void* getTopAS(ArrayStack* as)
{
	return as->pArray[as->count - 1];
}

boolean fullAS(ArrayStack* as)
{
	return as->max == as->count;
}

boolean isEmptyAS(ArrayStack* as)
{
	return as->count == 0;
}

int sizeAS(ArrayStack* as)
{
	return as->count;
}

void clearARRAYSTACK(ArrayStack* as)
{
	for(int i = as->count - 1; i != -1; --i)
		free(as->pArray[i]);
	as->count = 0;
} 

void* findAS(ArrayStack* as, const void* key, Equals equals)
{
	for(int i = as->count - 1; i != -1; --i)
	{
		if (equals(as->pArray[i], key))
			return as->pArray[i];
	}
	return NULL;
}
