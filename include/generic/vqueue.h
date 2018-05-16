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
 * @file	vqueue.h
 *
 * @brief	Queue adapter for vector.
 */
#ifndef	DATA_STRUCTURE_QUEUE
#define	DATA_STRUCTURE_QUEUE

#include <stddef.h>	// size_t
#include <generic/vector.h>


/** @brief Data structure of a queue
 *
 * The members are identical to vector
 */
typedef gVector gVQueue;

/**
 * Function: gVQueueCreate
 * -----------------------
 * Initialize the queue
 *
 * @param queue 	Queue being initialized
 * @param size 		Size of each element
 *
 */
void gVQueueCreate(gVQueue *queue, size_t size);

/**
 * Function: gVQueueInsert
 * ---------------------
 * Push to the end of the queue
 *
 * @param queue     Queue to be pushed
 * @param val       Pointer to the pushing value
 *
 */
void gVQueueInsert(gVQueue *queue, void *val);

/**
 * Function: gVQueueRemove
 * Remove the first element
 *
 * @param queue:	Queue holding the elements
 *
 * @return	Pointer to the popped value
 *		It may be overrided by the next push
 */
void *gVQueueRemove(gVQueue *queue);

/**
 * Function: gVQueueDestroy
 * ------------------------
 * Destroy the queue
 *
 * @param queue     The queue being destroyed
 */
void gVQueueDestroy(gVQueue *queue);


#endif

