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

/* add Datas Type Primitive (addDTP.h) */
#ifndef _ADD_DTP_H
#define _ADD_DTP_H


#define addDTP(expr)                   		\
   _Generic((expr),                  		\
   char      		 	: add_char,         \
   unsigned char     	: add_uchar,        \
   short             	: add_short,        \
   int               	: add_int,          \
   long              	: add_long,         \
   long long         	: add_longLong,     \
   unsigned short    	: add_ushort,       \
   unsigned int      	: add_uint,         \
   unsigned long     	: add_ulong,        \
   unsigned long long   : add_ulongLong,    \
   float   				: add_float,        \
   double    			: add_double,       \
   long double   		: add_longDouble,   \
   char*    			: add_string,       \
   default   		 	: add_value_default \
)(expr)


void* add_char(char);
void* add_uchar(unsigned char);
void* add_short(short);
void* add_int(int);
void* add_long(long);
void* add_longLong(long long);
void* add_ushort(unsigned short);
void* add_uint(unsigned int);
void* add_ulong(unsigned long);
void* add_ulongLong(unsigned long long);
void* add_float(float);
void* add_double(double);
void* add_longDouble(long double);
void* add_string(const char*);
void* add_value_default(void*);

#endif /* _ADD_DTP_H */
