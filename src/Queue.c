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

#include "lst/LinkedList.h"
#include "lst/Queue.h"
#include <stdlib.h>

boolean addLastQE(Queue* qe, void* object)
{
	ListNode* newNode = createNode(qe, object, sizeof(ListNode));
	if(newNode == NULL)
		return true;
	(qe->pBegin == NULL) ? (qe->pBegin = newNode) : (qe->pEnd->next = newNode);
	newNode->next = NULL;
	qe->pEnd = newNode;
	++qe->count;
	newNode->object = object;
	return false;
}

void* removeFirstQE(Queue* qe)
{
	ListNode* aux;
	void* ob;
	if(qe->pBegin == NULL)
		return NULL;
	aux = qe->pBegin;
	ob = aux->object;
	--qe->count;
	qe->pBegin = qe->pBegin->next;
	free(aux);
	return ob;
}

void* getFrontQE(Queue* qe)
{
	return qe->pBegin->object;
}
