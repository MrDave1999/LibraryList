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

#ifndef _QUEUE_H
#define _QUEUE_H

struct ListNode
{
	void* object;
	struct ListNode* next;
};

struct Queue
{
	int i;
	int count;
	struct ListNode* pBegin;
	struct ListNode* aux;
	struct ListNode* pEnd;
};

typedef struct Queue Queue;
typedef struct ListNode ListNode;
#define newQueue() new_object_list(LINKEDLIST, sizeof(Queue))

boolean addLastQE(Queue*, void*);
void* removeFirstQE(Queue*);
void* getFrontQE(Queue*);

#endif /* _QUEUE_H */
