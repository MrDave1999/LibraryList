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

#ifndef _FOREACH_H
#define _FOREACH_H

void* getNextElementAL(ArrayList*);
void* getNextElementLK(LinkedList*);

#define getNextElement(expr) \
	_Generic((expr), \
		ArrayList*  : getNextElementAL((ArrayList*)expr), \
		LinkedList* : getNextElementLK((LinkedList*)expr), \
		Stack* : 	  getNextElementLK((LinkedList*)expr) \
	)
	
#define foreach(type, nameVar, _ptr) \
	_ptr->i = 0; \
	for(type* nameVar; _ptr->i != _ptr->count && (nameVar = getNextElement(_ptr)) != NULL; ++_ptr->i)

#endif /* _FOREACH_H */
