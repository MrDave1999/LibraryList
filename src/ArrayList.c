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
#define CAPACITY_DEFAULT	(10)

boolean addAL(ArrayList* al, void* object)
{
	size_t newCapacity;
	if (al == NULL || object == NULL)
	{
		free(object);
		return EXIT_FAILURE;
	}
	++al->count;
	if (al->ptr == NULL)
	{
		if (al->capacity == 0)
			al->capacity = CAPACITY_DEFAULT;
		if (setCapacity(al, al->capacity))
		{
			free(object);
			return EXIT_FAILURE;
		}
	}
	else
	{
		if (al->count > al->capacity)
		{
			newCapacity = (al->capacity) + (al->capacity >> 1);
			if (setCapacity(al, newCapacity))
			{
				free(object);
				return EXIT_FAILURE;
			}
		}
	}
	al->ptr[(al->count) - 1] = object;
	return EXIT_SUCCESS;
}

void* getAL(ArrayList* al, const size_t index)
{
	return (index >= 0 && index < al->count) ? (al->ptr[index]) : (NULL);
}

void* setAL(ArrayList* al, const size_t index, void* newObject)
{
	void* prevObject = NULL;
	if((newObject != NULL) && (index >= 0 && index < al->count))
	{
		prevObject = al->ptr[index];
		al->ptr[index] = newObject;
	}
	return prevObject;
}

boolean removeAL(ArrayList* al, const void* key, Equals equals)
{
	for (int i = 0; i != al->count; ++i)
	{
		if (equals(al->ptr[i], key))
		{
			iremoveAL(al, i);
			return false;
		}
	}
	return true;
}

boolean removeAll_AL(ArrayList* al, const void* key, Equals equals)
{
	boolean isExist = true;
	for (int i = 0; i != al->count; ++i)
	{
		if (equals(al->ptr[i], key))
		{
			iremoveAL(al, i);
			--i;
			isExist = false;
		}
	}
	return isExist;
}

boolean iremoveAL(ArrayList* al, const size_t index)
{
	if (index >= 0 && index < al->count)
	{
		free(al->ptr[index]);
		for (int i = index + 1; i != al->count; ++i)
			al->ptr[i - 1] = al->ptr[i];
		--al->count;
		return false;
	}
	return true;
}

void clearAL(ArrayList* al)
{  
	if (al->count != 0)
	{
		for (int i = 0; i != al->count; ++i)
			free(al->ptr[i]);
		free(al->ptr);
		al->count = 0;
		al->capacity = 0;
		al->ptr = NULL;
	}  
}

void* findAL(ArrayList* al, const void* key, Equals equals)
{
	for (int i = 0; i != al->count; ++i)
	{
		if (equals(al->ptr[i], key))
			return al->ptr[i];
	}
	return NULL;
}

size_t sizeAL(ArrayList* al)
{
	return al->count;
}

boolean isEmptyAL(ArrayList* al)
{
	return al->ptr == NULL;
}

void* bSearch(ArrayList* al, const void* key, Compare compare)
{
	int first = 0;
	int end = al->count - 1;
	int medium;
	while (first <= end)
	{
		medium = (first + end) / 2;
		if (compare(al->ptr[medium], key) == 0)
			return al->ptr[medium];
		(compare(al->ptr[medium], key) < 0) ? (first = medium + 1) : (end = medium - 1);
	}
	return NULL;
}

void bsortAL(ArrayList* al, Compare compare)
{
	void* aux;
	size_t len = al->count;
	boolean change = false;
	while(1)
	{
		for(int i = 1; i != len; ++i)
		{
			if(compare(al->ptr[i - 1], al->ptr[i]) > 0)
			{			
				aux = al->ptr[i];
				al->ptr[i] = al->ptr[i - 1];
				al->ptr[i - 1] = aux;
				change = true;
			}	
		}
		if(!change) break;
		--len;
		change = false;
	}
}

void* minAL(ArrayList* al, Compare compare)
{
	void* candidate;
	if(al->count == 0)
		return NULL;
	candidate = al->ptr[0];
	for(int i = 1; i != al->count; ++i)
	{
		if(compare(al->ptr[i], candidate) < 0)
			candidate = al->ptr[i];
	}
	return candidate;
}

void* maxAL(ArrayList* al, Compare compare)
{
	void* candidate;
	if(al->count == 0)
		return NULL;
	candidate = al->ptr[0];
	for(int i = 1; i != al->count; ++i)
	{
		if(compare(al->ptr[i], candidate) > 0)
			candidate = al->ptr[i];
	}
	return candidate;
}


boolean setCapacity(ArrayList* al, const size_t newCapacity)
{
	if (newCapacity <= 0 || newCapacity < al->count)
		return EXIT_FAILURE;
	void* temp;
	temp = al->ptr;
	al->capacity = newCapacity;
	al->ptr = realloc(al->ptr, newCapacity * sizeof(void*));
	if (al->ptr == NULL)
	{
		al->ptr = temp;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
