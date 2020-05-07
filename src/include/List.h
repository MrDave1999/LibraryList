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

#include "LinkedList.h"
#include "ArrayList.h"
#include "foreach.h"
#include "addDTP.h"
#include "Queue.h"
#include "Stack.h"

extern LinkedList registers[MAX_LISTS];

#define add(expr, obj) \
	_Generic((expr), \
		ArrayList*  : addAL, \
		LinkedList* : addLK \
	)(expr, addDTP(obj))

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
		ArrayList*  : clearAL, \
		LinkedList* : clearLK, \
		Stack* : clear_stack \
	)(expr)
	
#define find(expr, key, equals) \
	_Generic((expr), \
		ArrayList*  : findAL, \
		LinkedList* : findLK \
	)(expr, key, equals)
	
#define size(expr) \
	_Generic((expr), \
		ArrayList*  : sizeAL, \
		LinkedList* : sizeLK, \
		Stack* : size_stack \
	)(expr)

#define isEmpty(expr) \
	_Generic((expr), \
		ArrayList*  : isEmptyAL, \
		LinkedList* : isEmptyLK, \
		Stack* : isEmpty_stack \
	)(expr)

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
		LinkedList* : deleteLK(expr), \
		Stack* : delete_stack(expr) \
	)

#endif /* _LIST_H */
