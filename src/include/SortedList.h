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

#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#define addSorted(expr, obj) insertOrder(expr, addDTP(obj))
#define newSortedList(compare) newSL(sizeof(SortedList), compare)

struct SortedList
{
	struct LinkedList lk;
	Compare compare;
};

typedef struct SortedList SortedList;

LinkedList* newSL(size_t, Compare);
boolean insertOrder(LinkedList*, void*);
void* findSorted(LinkedList*, const void*, const void*, Equals);
void searchPosition_Node(LinkedList*, const void*, Node*);

#endif /* _SORTEDLIST_H */
