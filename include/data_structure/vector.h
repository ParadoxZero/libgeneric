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
 * @file	vector.h
 *
 * @brief	C equivalence to std::vector
 */
#ifndef	DATA_STRUCTURE_VECTOR_H
#define	DATA_STRUCTURE_VECTOR_H
#include <stddef.h>	// size_t

/** @defgroup vector Generic Vector
 * Generic Vector is a C equivalence to C++'s std::vector
 * @author Travor Liu
 * @{
 */

/** @brief Default number of elements of vector
 *
 * It is used during initialization
 */
#define	VECTOR_DEFAULT_ELEMS	16

/** @brief The structure of vector
 *
 * Assuming those members are read-only
 */
typedef struct vector_struct {
	/** @brief Pointer to the elements 
	 * Only changed due to a resize
	 */
	void *elems;
	/** @brief Size of each elements
	 * Only changed due to initialization
	 */
	size_t elem_sz;
	/** @brief Number of elements */
	size_t n;	
	/** @brief Allocated size of elems
	 * Only changed due to a resize
	 */
	size_t alloc;
} vector_t;

/** @brief Initialize the vector
 *
 * Initialize the vector with a specific size of each element
 *
 * @param vector:	Vector to be initialized
 * @param size:		Size for each elements
 */
extern void vector_new(vector_t *vector,size_t size);

/** @brief Destroy the vector
 *
 * It frees the memory and reset everything in the vector
 *
 * @param vector:	Vector to be destroyed
 */
extern void vector_destroy(vector_t *vector);

/** @brief Add an element to the back of the vector
 *
 * It doubles vector_t::alloc if n*elem_sz>alloc
 *
 * @param vector:	Vector to be pushed
 * @param value:	Pointer to the pushing value
 *
 * @see vector_t::n
 * @see vector_t::alloc
 */
extern void vector_push_back(vector_t *vector,void *value);

/** @brief Pop an element from the back of the vector
 *
 * It decreases length of the vector.
 *
 * @param vector:	Vector to be popped
 *
 * @return	Pointer to the popped value
 *		This value may be overrided in the next push
 */
extern void *vector_pop_back(vector_t *vector);

/** @brief Get the element at the specific location
 *
 * @param vector:	Vector that holds the elements
 * @param index:	The index of the element
 *
 * @return	Pointer to the element
 */
extern void *vector_at(vector_t *vector,size_t index);

/** @brief Resize the vector
 *
 * Reallocates the elements in the vector
 *
 * @param vector:	Vector to be resized
 * @param new_size:	The new size for the vector
 *
 * @see	vector_t::alloc
 */
extern void vector_resize(vector_t *vector,size_t new_size);

/** @brief Get the first element
 *
 * @param vector:	Vector that holds the elements
 *
 * @return	the pointer to the first element
 */
extern void *vector_front(vector_t *vector);

/** @brief Get the last element
 *
 * @param vector:	Vector that holds the elements
 *
 * @return	the pointer to the last element
 *
 * @see	vector_t::elems
 */
extern void *vector_back(vector_t *vector);

/** @brief Set the value at position
 *
 * @param vector:	Vector that holds the elements
 * @param pos:	Where to put the value
 * @param val:	Pointer to the value
 *
 * @return	Position of the value
 */
extern void *vector_set(vector_t *vector,size_t pos,void *val);

/** @brief Insert value before position
 *
 * 1. Shifts the elements after pos
 * 2. Put the val at pos
 *
 * @param vector:	Vector that holds the elements
 * @param pos:	Where to insert
 * @param val:	Pointer to the value
 *
 * @return	Pointer to the inserted value
 */
extern void *vector_insert(vector_t *vector,size_t pos,void *val);

/** @} */
#endif

