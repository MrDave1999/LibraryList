#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "MemoryManagement.h"

struct Node
{
	void* object;
	struct Node* sig;
};

struct LinkedList
{
	struct Node* pBegin;
	struct Node* pEnd;
	struct Node* aux;
	size_t count;
};

typedef struct LinkedList LinkedList;
typedef struct Node Node;

#define newLinkedList() (LinkedList*)__new__(LINKEDLIST, sizeof(LinkedList))
#define freeObjectLK(objectLK) freeObject(LINKEDLIST, objectLK, clearLK)
#define forLK(type, nameVar, ptr) \
	ptr->aux = ptr->pBegin; \
	for(type* nameVar; ptr->aux != NULL && (nameVar = (type*)ptr->aux->object) != NULL; ptr->aux = ptr->aux->sig)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

uint8_t addLK(LinkedList* lk, void* newObject);
void clearLK(void* lk);
void* getLK(LinkedList* lk, size_t index);
void* setLK(LinkedList* lk, size_t index, void* newObject);
uint8_t removeLK(LinkedList* lk, int(*funcComparator)(void*), const uint8_t option);
uint8_t iremoveLK(LinkedList* lk, size_t index);
void removeElement(LinkedList* lk, Node* penNode);
void* findLK(LinkedList* lk, int(*funcComparator)(void*));
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LINKEDLIST_H */
