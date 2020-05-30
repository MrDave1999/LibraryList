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

#ifndef _LIST_H
#define _LIST_H

#include "MemoryManagement.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "foreach.h"
#include "addDTP.h"
#include "isRange.h"
#include "Queue.h"
#include "Stack.h"
 
#define push(expr, obj) \
	_Generic((expr), \
		Stack*  : addFirstST, \
		LinkedList* : addFirstLK \
	)(expr, addDTP(obj))

#define enqueue(expr, obj) \
	_Generic((expr), \
		Queue*  : addLastQE, \
		LinkedList* : addLastLK \
	)(expr, addDTP(obj))

#define add(expr, obj) \
	_Generic((expr), \
		ArrayList*  : addLastAL, \
		LinkedList* : addLastLK \
	)(expr, addDTP(obj))

#define add_i(expr, index, obj) \
	_Generic((expr), \
		ArrayList*  : addAL_Index, \
		LinkedList* : addLK_Index \
	)(expr, index, addDTP(obj))
	
#define get(expr, index) \
	_Generic((expr), \
		ArrayList*  : getAL, \
		LinkedList* : getLK \
	)(expr, index)
	
#define set(expr, index, newObject) \
	_Generic((expr), \
		ArrayList*  : setAL, \
		LinkedList* : setLK \
	)(expr, index, addDTP(newObject))

#define dequeue(expr) \
	_Generic((expr), \
		Queue*  : removeFirstQE, \
		LinkedList* : removeFirstLK \
	)(expr)
	
#define pop(expr) \
	_Generic((expr), \
		Stack*  : removeFirstST, \
		LinkedList* : removeFirstLK \
	)(expr)
	
#define oremove(expr, key, equals) \
	_Generic((expr), \
		ArrayList*  : removeAL, \
		LinkedList* : removeLK \
	)(expr, key, equals)

#define removeAll(expr, key, equals) \
	_Generic((expr), \
		ArrayList*  : removeAll_AL, \
		LinkedList* : removeAll_LK \
	)(expr, key, equals)	
	
#define iremove(expr, index) \
	_Generic((expr), \
		ArrayList*  : iremoveAL, \
		LinkedList* : iremoveLK \
	)(expr, index)
	
#define clear(expr) \
	_Generic((expr), \
		ArrayList*  : clearAL((ArrayList*)expr), \
		LinkedList* : clearLK((LinkedList*)expr),  \
		Stack* : 	clearLK((LinkedList*)expr),  \
		Queue* : 	clearLK((LinkedList*)expr)  \
	)
	
#define find(expr, key, equals) \
	_Generic((expr), \
		ArrayList*  : findAL((ArrayList*)expr, key, equals), \
		LinkedList* : findLK((LinkedList*)expr, key, equals), \
		Stack* : findLK((LinkedList*)expr, key, equals), \
		Queue* : findLK((LinkedList*)expr, key, equals)  \
	)
	
#define size(expr) \
	_Generic((expr), \
		ArrayList*  : sizeAL((ArrayList*)expr), \
		LinkedList* : sizeLK((LinkedList*)expr),  \
		Stack* : sizeLK((LinkedList*)expr), \
		Queue* : sizeLK((LinkedList*)expr)  \
	)

#define isEmpty(expr) \
	_Generic((expr), \
		ArrayList*  : isEmptyAL((ArrayList*)expr), \
		LinkedList* : isEmptyLK((LinkedList*)expr),  \
		Stack* : isEmptyLK((LinkedList*)expr), \
		Queue* : isEmptyLK((LinkedList*)expr)  \
	)

#define bsort(expr, compare) \
	_Generic((expr), \
		ArrayList*  : bsortAL, \
		LinkedList* : bsortLK \
	)(expr, compare)
	
#define min(expr, compare) \
	_Generic((expr), \
		ArrayList* : minAL, \
	    LinkedList*: minLK \
	)(expr, compare)

#define max(expr, compare) \
	_Generic((expr), \
		ArrayList* : maxAL, \
	    LinkedList*: maxLK  \
	)(expr, compare)
			
#define delete(expr) \
	_Generic((expr), \
		ArrayList*  : deleteAL(expr), \
		LinkedList* : deleteLK(expr),  \
		Stack* : deleteLK(expr),  \
		Queue* : deleteLK(expr)  \
	)

#define getTop(expr) \
	_Generic((expr), \
		Stack*  : getTopST((Stack*)expr), \
		LinkedList* : getTopST((Stack*)expr)  \
	)

#define getFront(expr) \
	_Generic((expr), \
		Queue*  : getFrontQE((Queue*)expr), \
		LinkedList* : getFrontQE((Queue*)expr)  \
	)

#endif /* _LIST_H */
