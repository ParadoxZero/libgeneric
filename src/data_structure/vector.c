/*
 *   MIT License
 *
 *   Copyright (c) 2018 Travor Liu
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

#include <data_structure/vector.h>
#include <assert.h>
#include <string.h>

void vector_new(vector_t *vector,size_t size)
{
	assert(vector!=NULL);
	assert(size>0);
	vector->alloc=VECTOR_DEFAULT_ELEMS*size;
	vector->n=0;
	vector->elems=malloc(vector->alloc);
	vector->elem_sz=size;
}

void vector_destroy(vector_t *vector)
{
	free(vector->elems);
	vector->elems=NULL;
	vector->n=0;
	vector->elem_sz=0;
	vector->alloc=0;
}

void vector_push_back(vector_t *vector,void *val)
{
	assert(vector!=NULL);
	assert(val!=NULL);
	size_t size=(vector->elem_sz)*(vector->n);
	char *ptr=(char*)vector->elems;
	/* If the required size is more than alloc, double the allocated space */
	if(size>=vector->alloc){
		vector_resize(vector,size);
	}
	/* Copy the value to the end of the vector */
	memcpy(ptr+size,val,vector->elem_sz);
	vector->n++;	// Increase the logical size
}

void *vector_pop_back(vector_t *vector)
{
	assert(vector!=NULL);
	if(vector->n<1){
		return NULL;
	}
	void *ptr=vector_back(vector);
	vector->n--;
	return ptr;
}

void vector_resize(vector_t *vector,size_t new_size)
{
	assert(vector!=NULL);
	size_t tmp=new_size*vector->elem_sz;
	vector->alloc=tmp;
	vector->n=new_size;
	vector->elems=realloc(vector->elems,tmp);
}

void *vector_front(vector_t *vector)
{
	assert(vector!=NULL);
	return vector->elems;
}

void *vector_back(vector_t *vector)
{
	if(vector->n==0){
		return vector->elems;
	}
	return vector_at(vector,vector->n-1);
}

void *vector_at(vector_t *vector,size_t index)
{
	assert(vector!=NULL);
	size_t size=index*vector->elem_sz;
	char *ptr=(char*)vector->elems;
	return ptr+size;
}

void *vector_set(vector_t *vector,size_t pos,void *val)
{
	void *ptr=vector_at(vector,pos);
	memcpy(ptr,val,vector->elem_sz);
	return ptr;
}

void *vector_insert(vector_t *vector,size_t pos,void *val)
{
	assert(vector!=NULL);
	char *ptr=(char*)vector_at(vector,pos);
	char *ptr2=(char*)vector_back(vector);
	size_t size=ptr2-ptr;
	vector_push_back(vector,ptr2);	// Put the last value at the back
	memmove(ptr+vector->elem_sz,ptr,size);
	vector_set(vector,pos,val);
	return ptr;
}

