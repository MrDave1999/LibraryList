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
#include "lst/LinkedQueue.h"
#include "lst/LinkedStack.h"
 
boolean addFirstLS(LinkedStack* st, void* object)
{
	ListNode* newNode = createNode(st, object, sizeof(ListNode));
	if(newNode == NULL)
		return true;
	newNode->object = object;
	++st->count;
	newNode->next = st->pTop;
	st->pTop = newNode;
	return false;
}

void* removeFirstLS(LinkedStack* st)
{
	return removeFirstLQ((LinkedQueue*)st);
}

void* getTopLS(LinkedStack* st)
{
	return st->pTop->object;
}

void clearLINKEDSTACK(LinkedStack* st)
{
	clearLINKEDLIST((LinkedList*)st);
}
