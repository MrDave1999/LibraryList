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

#include <string.h>
#include <stdlib.h>

#define defFunction_add(type, nameFunction) \
void* nameFunction(type value) 				\
{ 											\
	type* ptr = malloc(sizeof(type)); 		\
	if(ptr != NULL) 						\
		*ptr = value; 						\
	return ptr; 							\
}


defFunction_add(char, 				add_char)
defFunction_add(unsigned char, 		add_uchar)
defFunction_add(short, 				add_short)
defFunction_add(int, 				add_int)
defFunction_add(long, 				add_long)
defFunction_add(long long, 			add_longLong)
defFunction_add(unsigned short, 	add_ushort)
defFunction_add(unsigned int, 		add_uint)
defFunction_add(unsigned long, 		add_ulong)
defFunction_add(unsigned long long, add_ulongLong)
defFunction_add(float, 				add_float)
defFunction_add(double, 			add_double)
defFunction_add(long double, 		add_longDouble)

void* add_string(const char* str)
{
	size_t len = strlen(str) + 1;
	char* ptr = malloc(len * sizeof(char));
	if(ptr != NULL)
		strcpy(ptr, str);
	return ptr;
}

void* add_value_default(void* p)
{
	return p;
}
