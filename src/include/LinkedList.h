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

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "def.h"

struct Node
{
	void* object;
	struct Node* next;
	struct Node* prev;
};

struct LinkedList
{
	int i;
	int count;
	struct Node* pBegin;
	struct Node* aux;
	struct Node* pEnd;
};

typedef struct LinkedList LinkedList;
typedef struct Node Node;

#include "SortedList.h"
#define newLinkedList() new_object_list(LINKEDLIST, sizeof(LinkedList))
#define deleteLK(objectLK) delete_object_list(LINKEDLIST, objectLK, (void(*)(void*))clearLK)

void* createNode(void*, void*, size_t);
boolean addLastLK(LinkedList*, void*);
boolean addFirstLK(LinkedList*, void*);
boolean addLK_Index(LinkedList*, const int, void*);
void* getLK(LinkedList*, const int);
void* setLK(LinkedList*, const int, void*);
void* removeFirstLK(LinkedList* lk);
boolean removeLK(LinkedList*, const void*, Equals);
boolean removeAll_LK(LinkedList*, const void*, Equals);
boolean iremoveLK(LinkedList*, const int);
void removeNode(LinkedList*);
void clearLK(LinkedList*);
void* findLK(LinkedList*, const void*, Equals);
int sizeLK(LinkedList*);
boolean isEmptyLK(LinkedList*);
boolean bsortLK(LinkedList*, Compare);
void* minLK(LinkedList*, Compare);
void* maxLK(LinkedList*, Compare);

#endif /* _LINKEDLIST_H */
