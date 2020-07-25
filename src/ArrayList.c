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
#include "lst/isRange.h"
 
boolean addLastAL(ArrayList* al, void* object)
{
	if (al == NULL || object == NULL)
	{
		free(object);
		return true;
	}
	if (al->pArray == NULL)
	{
		if (al->capacity == 0)
			al->capacity = CAPACITY_DEFAULT;
		if (setCapacity(al, al->capacity))
		{
			free(object);
			return true;
		}
	}
	else if (al->count == al->capacity && setCapacity(al, NEW_CAPACITY(al)))
	{
		free(object);
		return true;
	}
	al->pArray[++al->count - 1] = object;
	return false;
}

boolean addAL_Index(ArrayList* al, const int index, void* object)
{
	void* elementCurrent, *elementPrev;
	if(al == NULL || object == NULL)
	{
		free(object);
		return true;
	}
	if(al->count == al->capacity && setCapacity(al, NEW_CAPACITY(al)))
	{
		free(object);
		return true;
	}
	elementPrev = al->pArray[index];
	al->pArray[index] = object;
	++al->count;
	for(int i = index+1; i != al->count; ++i)
	{
		elementCurrent = al->pArray[i];
		al->pArray[i] = elementPrev;
		elementPrev = elementCurrent;
	}
	return false;
}

void* getAL(ArrayList* al, const int index)
{
	return (isRange(al, index)) ? (NULL) : (al->pArray[index]);
}

void* setAL(ArrayList* al, const int index, void* newObject)
{
	void* prevObject = NULL;
	if(newObject != NULL)
	{
		prevObject = al->pArray[index];
		al->pArray[index] = newObject;
	}
	return prevObject;
}

boolean removeAL(ArrayList* al, const void* key, Equals equals)
{
	for (int i = 0; i != al->count; ++i)
	{
		if (equals(al->pArray[i], key))
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
		if (equals(al->pArray[i], key))
		{
			iremoveAL(al, i);
			--i;
			isExist = false;
		}
	}
	return isExist;
}

boolean iremoveAL(ArrayList* al, const int index)
{
	if(isRange(al, index))
		return true;
	free(al->pArray[index]);
	for (int i = index + 1; i != al->count; ++i)
		al->pArray[i - 1] = al->pArray[i];
	--al->count;
	return false;
}

boolean rremoveAL(ArrayList* al, const int indexFirst, const int indexEnd)
{
	if(isRange(al, indexFirst) || isRange(al, indexEnd) || indexFirst > indexEnd)
		return true;
	int amount = (indexEnd - indexFirst) + 1;
	for(int i = 0; i != amount; ++i)
		iremoveAL(al, indexFirst);
	return false;
} 

void clearARRAYLIST(ArrayList* al)
{  
	for (int i = 0; i != al->count; ++i)
		free(al->pArray[i]);
	free(al->pArray);
	al->count = 0;
	al->capacity = 0;
	al->pArray = NULL;
}

void* findAL(ArrayList* al, const void* key, Equals equals)
{
	for (int i = 0; i != al->count; ++i)
	{
		if (equals(al->pArray[i], key))
			return al->pArray[i];
	}
	return NULL;
}

int sizeAL(ArrayList* al)
{
	return al->count;
}

boolean isEmptyAL(ArrayList* al)
{
	return al->pArray == NULL;
}

boolean setCapacity(ArrayList* al, int newCapacity)
{
	void* temp;
	temp = al->pArray;
	al->capacity = newCapacity;
	al->pArray = realloc(al->pArray, newCapacity * sizeof(void*));
	if (al->pArray == NULL)
	{
		al->pArray = temp;
		return true;
	}
	return false;
}
