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
 
#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "def.h" 

struct ArrayList
{
	void** pArray;
	int i;
	int capacity;
	int count;
};

typedef struct ArrayList ArrayList;

#define CAPACITY_DEFAULT	(10)
#define NEW_CAPACITY(expr) 	((expr->capacity) + (expr->capacity >> 1))
#define newArrayList() new_object(ARRAYLIST, sizeof(ArrayList))
#define deleteAL(objectAL) delete_object(ARRAYLIST, objectAL, (void(*)(void*))clearARRAYLIST)

boolean addLastAL(ArrayList*, void*);
boolean addAL_Index(ArrayList*, const int, void*);		
void* getAL(ArrayList*, const int);
void* setAL(ArrayList*, const int, void*);
boolean removeAL(ArrayList*, const void*, Equals);
boolean removeAll_AL(ArrayList*, const void*, Equals);
boolean iremoveAL(ArrayList*, const int);
boolean rremoveAL(ArrayList*, const int, const int);
void clearARRAYLIST(ArrayList*);
void* findAL(ArrayList*, const void*, Equals);
int sizeAL(ArrayList*);
boolean isEmptyAL(ArrayList*);
boolean setCapacity(ArrayList*, const int);

#endif /* _ARRAYLIST_H */
