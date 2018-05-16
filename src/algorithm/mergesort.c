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

#include <algorithm/merge_sort.h>
#include <string.h>
#include <assert.h>
/** @addtogroup mergesort
 * @{
 */

/** @brief Internal function that does merging
 *
 * It helps merge two sublists
 *
 * @param arr:	Array containing the sublists
 * @param beg:	Start of first sublist
 * @param mid:	End of first sublist
 * @param end:	End of second sublist
 */
static void do_merge(int *arr,size_t beg,size_t mid,size_t end)
{
	int tmp[end-beg+1];
	size_t i=beg,j=mid+1,k=0;
	// Move the smaller number to the new array
	while(i<=mid&&j<=end){
		if(arr[i]<arr[j]){
			tmp[k++]=arr[i++];
		}else{
			tmp[k++]=arr[j++];
		}
	}
	// Move the remaining of the left block
	while(i<=mid){
		tmp[k++]=arr[i++];
	}
	// Move the remaining of the right block
	while(j<=end){
		tmp[k++]=arr[j++];
	}
	memcpy(arr+beg,tmp,sizeof(tmp));
}

/** @brief Internal function that splits the list
 *
 * It is called recursively in order to split everything to the smallest
 *
 * @param arr:	Array being splited
 * @param beg:	Begin of the section
 * @param end:	End of the section
 */
static void do_split(int *arr,size_t beg,size_t end)
{
	if(end-beg<1){
		return;
	}
	size_t mid=(beg+end)/2;
	do_split(arr,beg,mid);
	do_split(arr,mid+1,end);
	do_merge(arr,beg,mid,end);
}

int *merge_sort(int *arr,size_t n)
{
	assert(n>1);
	do_split(arr,0,n-1);
	return arr;
}

static void do_merge_generic(char *arr,size_t beg,size_t mid,size_t end,size_t elem_sz,cmpfunc_t cmpfunc)
{
	char tmp[elem_sz*(end-beg+1)];
	size_t i=beg,j=mid+1,k=0;
	int ret=0;
	while(i<=mid&&j<=end){
		ret=cmpfunc(arr+i*elem_sz,arr+j*elem_sz);
		if(ret<0){
			memcpy(tmp+k*elem_sz,arr+i*elem_sz,elem_sz);
			k++;
			i++;
		}else{
			memcpy(tmp+k*elem_sz,arr+j*elem_sz,elem_sz);
			k++;
			j++;
		}
	}
	while(i<=mid){
		memcpy(tmp+k*elem_sz,arr+i*elem_sz,elem_sz);
		k++;
		i++;
	}
	while(j<=end){
		memcpy(tmp+k*elem_sz,arr+j*elem_sz,elem_sz);
		k++;
		j++;
	}
	memcpy(arr+beg*elem_sz,tmp,sizeof(tmp));
}

static void do_split_generic(void *arr,size_t beg,size_t end,size_t elem_sz,cmpfunc_t cmpfunc)
{
	if(end-beg<=1){
		return;
	}
	size_t mid=(beg+end)/2;
	do_split_generic((char*)arr,beg,mid,elem_sz,cmpfunc);
	do_split_generic((char*)arr,mid+1,end,elem_sz,cmpfunc);
	do_merge_generic((char*)arr,beg,mid,end,elem_sz,cmpfunc);
}

void *merge_sort_generic(void *arr,size_t n,size_t elem_sz,cmpfunc_t cmpfunc)
{
	assert(cmpfunc!=NULL);
	assert(elem_sz>0);
	assert(n>1);
	do_split_generic(arr,0,n-1,elem_sz,cmpfunc);
	return arr;
}
/** @} */

