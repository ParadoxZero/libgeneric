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
/**
 * @file	mergesort.h
 *
 * @brief	A sorting algorithm created by John von Neumann in 1945
 */
#ifndef	ALGORITHM_MERGE_SORT_H
#define	ALGORITHM_MERGE_SORT_H
#include <stddef.h>	// size_t
#include <algorithm.h>
/** @defgroup mergesort Merge Sort
 *
 * Merge sort is a sorting algorithm originally created by John von Neumann
 * in 1945.
 *
 * @see https://en.wikipedia.org/wiki/Merge_sort
 *
 * @{
 */

/** @brief Merge Sort for integers
 *
 * @param arr:	Array being sorted
 * @param n:	Length of the array
 *
 * @return	Pointer to the sorted array
 *		Always equal to the input on success
 *		NULL on failure
 */
extern int *merge_sort(int *arr,size_t n);

/** @brief Merge Sort for generic types
 *
 * @param arr:	Array being sorted
 * @param n:	Length of the array
 * @param elem_sz:	Size of each element in the array
 * @param cmpfunc:	Function for comparing the elements
 *
 * @return	Pointer to the sorted array
 *		Always equal to the input on success
 *		NULL on failure
 *
 * @see	merge_sort
 */
extern void *merge_sort_generic(void *arr,size_t n,size_t elem_sz,cmpfunc_t cmpfunc);
/** @} */
#endif

