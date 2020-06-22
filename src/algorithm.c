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

#include "lst/algorithm.h"

static void** arrayElement;
static Compare cmp;

void quicksort(int first, int end)
{
	int i, j;
	void* pivote = arrayElement[(first + end) / 2];
	i = first;
	j = end;
	do
	{
		while(cmp(arrayElement[i], pivote) < 0) ++i;
		while(cmp(arrayElement[j], pivote) > 0) --j;
		if (i <= j)
		{
			swapElement(arrayElement[i], arrayElement[j]);
			++i;
			--j;
		}
	} while (i <= j);
	if (first < j)
		quicksort(first, j);
	if (i < end)
		quicksort(i, end);
}

boolean invoke_quicksort(ArrayList* al, Compare compare)
{
	if(al->count == 0)
		return true;
	if(al->count == 1)
		return false;
	arrayElement = al->pArray;
	cmp = compare;
	quicksort(0, al->count - 1);
	return false;
}

boolean bsortLK(LinkedList* lk, Compare compare)
{
	Node* aux;
	Node* pEnd = lk->pEnd;
	boolean change = false;
	if(lk->count == 0)
		return true;
	while(1)
	{
		aux = lk->pBegin;
		while(aux != pEnd)
		{
			if(compare(aux->object, aux->next->object) > 0)
			{			
				swapElement(aux->next->object, aux->object);
				change = true;
			}	
			aux = aux->next;
		}
		if(!change) break;
		pEnd = pEnd->prev;
		change = false;
	}
	return false;
}

boolean bsortAL(ArrayList* al, Compare compare)
{
	int len = al->count;
	if(len == 0)
		return true;
	boolean change = false;
	while(1)
	{
		for(int i = 1; i != len; ++i)
		{
			if(compare(al->pArray[i - 1], al->pArray[i]) > 0)
			{		
				swapElement(al->pArray[i], al->pArray[i - 1]);
				change = true;
			}	
		}
		if(!change) break;
		--len;
		change = false;
	}
	return false;
}
