#include <stdlib.h>
#include "ArrayList.h"
#define CAPACITY_DEFAULT	(10)

void* getAL(ArrayList* al, size_t index)
{
	return (index >= 0 && index < al->count) ? (al->ptr[index]) : (NULL);
}

void* setAL(ArrayList* al, size_t index, void* newObject)
{
	return (index >= 0 && index < al->count) ? ((al->ptr[index] = newObject)) : (NULL);
}

void clearAL(void* ptrAL)
{  
	ArrayList* al = ptrAL;
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

uint8_t setCapacity(ArrayList* al, const size_t newCapacity)
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
		freeALL();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

uint8_t addAL(ArrayList* al, void* object)
{
	size_t newCapacity;
	if (al == NULL)
	{
		free(object);
		freeALL();
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

uint8_t removeAL(ArrayList* al, int(*funcComparator)(void*), const uint8_t option)
{
	uint8_t isExist = 1;
	for (int i = 0; i != al->count; ++i)
	{
		if (funcComparator(al->ptr[i]))
		{
			iremoveAL(al, i);
			if (!option)
				--i;
			isExist = 0;
		}
		if (option && !isExist)
			break;
	}
	return isExist;
}

uint8_t iremoveAL(ArrayList* al, size_t index)
{
	if (index >= 0 && index < al->count)
	{
		free(al->ptr[index]);
		for (int i = index + 1; i != al->count; ++i)
			al->ptr[i - 1] = al->ptr[i];
		--al->count;
		return 0;
	}
	return 1;
}

void* findAL(ArrayList* al, int(*funcComparator)(void*))
{
	for (int i = 0; i != al->count; ++i)
	{
		if (funcComparator(al->ptr[i]))
			return al->ptr[i];
	}
	return NULL;
}
