/*
 *   MIT License
 *
 *   Copyright (c) 2017-2018 Travor Liu
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <data_structure/utils.h>
#include <string.h>	// memcpy and NULL

void swap_generic(void *a,void *b,size_t sz)
{
	char x[sz];
	memcpy(x,a,sz);	// Save A
	memcpy(a,b,sz);	// Copy B to A
	memcpy(b,x,sz);	// Copy saved A to B
}

void *search_generic(const void *key,const void *base,size_t n,size_t elem_sz)
{
	char *x=(char*)base;
	int i;
	for(i=0;i<n;i++){
		if(!memcmp(key,x,elem_sz)){
			return x;
		}
		x=(char*)x+elem_sz;
	}
	return NULL;
}

void *reverse_generic(void *elems,size_t n,size_t elem_sz)
{
	char *ptr=(char*)elems;
	int i,j;
	for(i=0,j=n-1;i<j;i++)
	{
		swap_generic(ptr+i*elem_sz,ptr+j*elem_sz,elem_sz);
	}
}

