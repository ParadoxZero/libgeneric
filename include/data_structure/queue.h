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
 * @file	queue.h
 *
 * @brief	Queue wrappers of vector
 */
#ifndef	DATA_STRUCTURE_QUEUE
#define	DATA_STRUCTURE_QUEUE
#include <stddef.h>	// size_t
#include <data_structure/vector.h>
/** @defgroup queue Generic Queue
 *
 * Queue is a container that provides FIFO ability to programmers
 *
 * Instead of creating another structure, I simply wrap the vector strucuture
 * The end of the queue will be the start of the vector where the start of queue
 * is the end of the vector
 *
 * @author Travor Liu
 *
 * @see vector
 *
 * @{
 */

/** @brief Data structure of a queue
 *
 * The members are identical to vector, so I typedef it
 */
typedef vector_t queue_t;

/** @brief Initialize the queue
 *
 * @param queue:	Queue being initialized
 * @param size:		Size of each element
 */
extern void queue_new(queue_t *queue,size_t size);

/** @brief Push to the end of the queue
 *
 * @param queue:	Queue to be pushed
 * @param val:	Pointer to the pushing value
 */
extern void queue_push(queue_t *queue,void *val);

/** @brief Remove the first element
 *
 * @param queue:	Queue holding the elements
 *
 * @return	Pointer to the popped value
 *		It may be overrided by the next push
 */
extern void *queue_pop(queue_t *queue);

/** @brief Destroy the queue
 *
 * @param queue:	The queue being destroyed
 */
extern void queue_destroy(queue_t *queue);

/** @} */
#endif
