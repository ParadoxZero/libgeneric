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
 * @brief	Dynamic array, the data is stored in contigeous memory locations.
 */

#ifndef	DATA_STRUCTURE_VECTOR_H
#define	DATA_STRUCTURE_VECTOR_H
#include <stddef.h>	// size_t
#include <stdlib.h>


/** @brief Default number of elements of vector
 *
 * It is used during initialization
 */
#define	VECTOR_DEFAULT_ELEMS	16

/** @brief The structure of vector
 *
 * Assuming those members are read-only
 */
typedef struct gVector {
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
} gVector;

/**
 *
 * Function: gVectorCreate
 * -----------------------
 * Initialize the vector with a specific size of each element
 *
 * @param vector	Vector to be initialized
 * @param size		Size for each elements
 */
void gVectorCreate(gVector *vector, size_t size);

/**
 * Function: gVectorDestroy
 * ------------------------
 * It frees the memory and reset everything in the vector
 *
 * @param vector	Vector to be destroyed
 */
void gVectorDestroy(gVector *vector);

/**
 * Function: gVectorPushBack
 * -------------------------
 * This will push an element to the end of vector.
 * It doubles vector_t::alloc if n*elem_sz>alloc
 *
 * @param vector	Vector to be pushed
 * @param value		Pointer to the pushing value
 *
 */
void gVectorPushBack(gVector *vector, void *value);

/**
 * Function: gVectorPopBack
 * ------------------------
 * Remove an element from the back of the vector
 * It decreases length of the vector.
 *
 * @param vector	Vector to be popped
 *
 * @return			Pointer to the popped value
 *					This value may be overridden in the next push
 */
void *gVectorPopBack(gVector *vector);

/**
 * Function: gVectorItemAt
 * -----------------------
 * Get the element at the specific location
 *
 * @param vector:	Vector that holds the elements
 * @param index:	The index of the element
 *
 * @return	Pointer to the element
 */
void *gVectorItemAt(gVector *vector, size_t index);

/**
 * Function: gVectorResize
 * -----------------------
 * Resize the vector
 * Reallocates the elements in the vector
 *
 * Warning: Data maybe lost in case of shrinking vector size.
 *
 * @param vector	Vector to be resized
 * @param new_size	The new size for the vector
 *
 */
void gVectorResize(gVector *vector, size_t new_size);

/**
 * Function: gVectorFront
 * ----------------------
 * Get the first element
 *
 * @param vector	Vector that holds the elements
 *
 * @return			The pointer to the first element
 */
void *gVectorFront(gVector *vector);

/**
 * Function: gVectorBack
 * ---------------------
 * Get the last element
 *
 * @param vector	Vector that holds the elements
 *
 * @return			The pointer to the last element
 *
 */
void *gVectorBack(gVector *vector);

/**
 * Function: gVectorSet
 * --------------------
 * Set the value at position
 *
 * @param vector	Vector that holds the elements
 * @param pos		Where to put the value
 * @param val		Pointer to the value
 *
 * @return			Position of the value
 */
void *gVectorSet(gVector *vector, size_t pos, void *val);

/**
 * Function: gVectorInsert
 * -----------------------
 * Insert value before position
 *
 * 1. Shifts the elements after pos
 * 2. Put the val at pos
 *
 * @param vector	Vector that holds the elements
 * @param pos		Where to insert
 * @param val		Pointer to the value
 *
 * @return			Pointer to the inserted value
 */
void *gVectorInsert(gVector *vector, size_t pos, void *val);

/* Optional Queue wrapper */
#ifdef	ENABLE_QUEUE

typedef gVector gQueue;

/**
 * Function: gQueueCreate
 * ----------------------
 * Create the queue
 *
 * @param queue	Queue being created
 * @param size	Size of each element in the queue
 */
#define	gQueueCreate(queue,size)	gVectorCreate(queue,size)

/**
 * Function: gQueueInsert
 * --------------------
 * Add an element to the back of the queue
 *
 * @param queue	Pointer to the pushed queue
 * @param val	Pointer to the pushing value
 */
#define	gQueueInsert(queue,val)	gVectorInsert(queue,0,val)

/** Function: gQueueRemove
 * --------------------
 * Remove an element from the front of the queue
 *
 * @param queue	Pointer to the popped queue
 *
 * @return	Pointer to the popped value
 *		May be overrided by the next push
 */
#define	gQueueRemove(queue)	gVectorPopBack(queue)

/**
 * Function: gQueueDestroy
 * -----------------------
 * Destroy the queue
 *
 * @param queue	Queue being destroyed
 */
#define	gQueueDestroy(queue)	gVectorDestroy(queue)
#endif

/** @} */
#endif

