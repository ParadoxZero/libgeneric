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
 * @file	merge_sort.h
 *
 * @brief	A sorting algorithm created by John von Neumann in 1945
 */
#ifndef	ALGORITHM_MERGE_SORT_H
#define	ALGORITHM_MERGE_SORT_H
#include <stddef.h>	// size_t
/** @defgroup sort Merge Sort
 *
 * Merge sort is a sorting algorithm originally created by John von Neumann
 * in 1945.
 *
 * There are two implementations for Merge Sort algorithm:
 * 1. Top-down: Recursively splits the list into sublist until sublist size
 * is 1, then merges those sublists to produce a sorted list
 * 2. Bottom-up: Treats the list as an array of n sublists of size 1, and iteratively
 * merges sub-lists back and forth between two buffers
 *
 * @see en.wikipedia.org/wiki/Merge_sort
 *
 * @{
 */

/** @brief Merge Sort using Top-down implementation
 *
 * @param arr:	Array being sorted
 * @param n:	Length of the array
 *
 * @return	pointer to the sorted array
 *		Always equal to the input on success
 *		NULL on failure
 */
extern int *topdown_merge_sort(int *arr,size_t n);

/** @} */
#endif

