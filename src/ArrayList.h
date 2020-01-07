#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "MemoryManagement.h"

struct ArrayList
{
	void** ptr;
	size_t count;
	size_t capacity;
	size_t i;
};

typedef struct ArrayList ArrayList;

#define newArrayList() (ArrayList*)__new__(ARRAYLIST, sizeof(ArrayList))

#define forAL(type, nameVar, _ptr) \
	_ptr->i = 0; \
	for(type* nameVar; _ptr->i != _ptr->count && (nameVar = (type*)_ptr->ptr[_ptr->i]) != NULL; ++_ptr->i)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void* getAL(ArrayList* al, size_t index);
void* setAL(ArrayList* al, size_t index, void* newObject);
void clearAL(void* al);
uint8_t setCapacity(ArrayList* al, const size_t newCapacity);
uint8_t addAL(ArrayList* al, void* refObject);
uint8_t removeAL(ArrayList* al, int(*funcComparator)(void*), const uint8_t option);
uint8_t iremoveAL(ArrayList* al, size_t index);
void* findAL(ArrayList* al, int(*funcComparator)(void*));
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _ARRAYLIST_H */
