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
 * @file    utils.h
 *
 * @brief   Utility functions.
 *
 */

#ifndef	DATA_STRUCTURE_UTILS_H
#define	DATA_STRUCTURE_UTILS_H

#include <stddef.h>	// size_t

/** @brief Swap bytes between two locations
 *
 * @param a	    The pointer to the first field
 * @param b	    The pointer to the second field
 * @param sz	The size of the field
 *
 * @return      Nothing.
 */
extern void gSwap(void *a, void *b, size_t sz);

/**
 * Function: gSwap
 * ---------------
 * Search matching bytes from a location
 *
 * @param key	    The bytes to search
 * @param base	    The elements to be searched
 * @param n 	    The number of elements in the base
 * @param elem_sz	The size of each element
 *
 * @return          The location where key is found or NULL if not found
 */
extern void *gSearch(const void *key, const void *base, size_t n, size_t elem_sz);

/**
 * Function: gReverse
 * ------------------
 * Reverse the elements in a contigous region e.g. Array/Vector
 *
 *  @param elems	Pointer to the elements
 *  @param n		Number of elements
 *  @param elem_sz	Size of each element
 *
 *  @return	        Pointer to the reversed elements
 *		            Always equal to elems
 */
extern void *gReverse(void *elems, size_t n, size_t elem_sz);


#endif
