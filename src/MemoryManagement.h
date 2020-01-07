#ifndef _MEMORYMANAGEMENT_H
#define _MEMORYMANAGEMENT_H

#include <stdint.h>

#define ALL			(0)
#define ONE			(1)

#define LINKEDLIST	(0)
#define ARRAYLIST	(1)

#define newObject(nameType) __newObject__(sizeof(nameType))

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void* __new__(size_t, size_t);
void freeALLEx(size_t, void(*__)(void*));
void freeALL(void);
void* __newObject__(size_t);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MEMORYMANAGEMENT_H */
