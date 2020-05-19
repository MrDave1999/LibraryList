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
	void** ptr;
	size_t capacity;
	size_t i;
	size_t count;
};

typedef struct ArrayList ArrayList;

#define newArrayList() new_object_list(ARRAYLIST, sizeof(ArrayList))
#define deleteAL(objectAL) delete_object_list(ARRAYLIST, objectAL, (void(*)(void*))clearAL)

boolean addAL(ArrayList*, void*);
boolean addAL_Index(ArrayList*, const size_t, void*);			
void* getAL(ArrayList*, const size_t);
void* setAL(ArrayList*, const size_t, void*);
boolean removeAL(ArrayList*, const void*, Equals equals);
boolean removeAll_AL(ArrayList*, const void*, Equals equals);
boolean iremoveAL(ArrayList*, const size_t);
void clearAL(ArrayList*);
void* findAL(ArrayList*, const void*, Equals equals);
size_t sizeAL(ArrayList*);
boolean isEmptyAL(ArrayList*);
void* bSearch(ArrayList*, const void*, Compare compare);
int bSearch_i(ArrayList*, const void*, Compare compare);
void bsortAL(ArrayList*, Compare compare);
void* minAL(ArrayList*, Compare compare);
void* maxAL(ArrayList*, Compare compare);
boolean setCapacity(ArrayList*, const size_t);

#endif /* _ARRAYLIST_H */
