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

#ifndef _ITERATOR_H
#define _ITERATOR_H

#define setDefault(expr) \
	_Generic((expr), \
		ArrayList*  : setDefaultAL((ArrayList*)expr), \
		LinkedList* : setDefaultLK((LinkedList*)expr), \
		LinkedStack* : setDefaultLK((LinkedList*)expr), \
		LinkedQueue* : setDefaultLK((LinkedList*)expr),  \
		ArrayQueue* : setDefaultAQ((ArrayQueue*)expr),    \
		ArrayStack* : setDefaultAS((ArrayStack*)expr)    \
	)

#define hasNext(expr) \
	_Generic((expr), \
		ArrayList*  : hasNextAL((ArrayList*)expr), \
		LinkedList* : hasNextLK((LinkedList*)expr), \
		LinkedStack* : hasNextLK((LinkedList*)expr), \
		LinkedQueue* : hasNextLK((LinkedList*)expr),  \
		ArrayQueue* : hasNextAQ((ArrayQueue*)expr),  \
		ArrayStack* : hasNextAS((ArrayStack*)expr)  \
	)

#define getNext(expr) \
	_Generic((expr), \
		ArrayList*  : getNextAL((ArrayList*)expr), \
		LinkedList* : getNextLK((LinkedList*)expr), \
		LinkedStack* : getNextLK((LinkedList*)expr), \
		LinkedQueue* : getNextLK((LinkedList*)expr),  \
		ArrayQueue* : getNextAQ((ArrayQueue*)expr),  \
		ArrayStack* : getNextAL((ArrayList*)expr)  \
	)

#define remv(expr) \
	_Generic((expr), \
		ArrayList*: removeElement_AL, \
		LinkedList*: removeElement_LK \
	)(expr)
		
void setDefaultAL(ArrayList*);
void setDefaultLK(LinkedList*);
void setDefaultAQ(ArrayQueue*);
void setDefaultAS(ArrayStack*);
boolean hasNextAL(ArrayList*);
boolean hasNextLK(LinkedList*);
boolean hasNextAQ(ArrayQueue*);
boolean hasNextAS(ArrayStack*);
void* getNextAL(ArrayList*);
void* getNextLK(LinkedList*);	
void* getNextAQ(ArrayQueue*);
void removeElement_AL(ArrayList*);
void removeElement_LK(LinkedList*);	
	
#endif /* _ITERATOR_H */
