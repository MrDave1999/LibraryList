#ifndef _MEMORYMANAGEMENT_H
#define _MEMORYMANAGEMENT_H

#include <stdint.h>

#define ALL			(0)
#define ONE			(1)

#define LINKEDLIST	(0)
#define ARRAYLIST	(1)

#define newObject(nameType) (nameType*)__newObject__(sizeof(nameType))

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void freeObject(size_t id, void* objectList, void(*clear)(void*));
void* __new__(size_t id, size_t size);
void freeALLEx(size_t id, void(*clear)(void*));
void freeALL(void);
void* __newObject__(size_t size);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MEMORYMANAGEMENT_H */
