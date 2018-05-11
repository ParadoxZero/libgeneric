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
 * @file	new_stack.h
 *
 * @brief	Vector-based implementation of stack
 */
#ifndef _DATA_STRUCTURE_STACK_H_
#define	_DATA_STRUCTURE_STACK_H_
#include <stddef.h>	// size_t

/** @defgroup stack Generic Stack
 * Generic Stack is implemented by Travor Liu.
 * The legacy one is implemented by Sidhin S Thomas
 * @see include/data_structure/stack.h
 * @{
 */

/** Default size of the stack */
#define	DEFAULT_STACKSZ	16

/**
 * @brief The data structure of stack
 *
 * Assuming the members are invisible to users
 */
typedef struct stack_struct {
	void *elems;	/**< The pointer to the elements of the stack */
	size_t logical;	/**< Logical size of the stack */
	size_t alloc;	/**< Allocated size of the stack */
} stack_t;

/**
 * @brief Create a new stack
 *
 * @param stack:	The pointer to the stack
 * @param sz:	The initial size of the stack.
 *		The size will be DEFAULT_STACKSZ if sz is zero
 */
extern void stack_init(stack_t *stack,size_t sz);

/**
 * @brief Push bytes to the stack
 *
 * It will double the size of the stack if there is no more space
 *
 * @param stack:	The pointer to the stack
 * @param val:	The pointer to the pushed value
 * @param sz:	Number of bytes being pushed to the stack
 */
extern void stack_push(stack_t *stack,void *val,size_t sz);

/**
 * @brief Pop bytes from stack
 *
 * @param stack:	The pointer to the stack
 * @param sz:	Number of bytes being popped from the stack
 *
 * @return:	The pointer to the popped value
 *		The value can be overrided by the next push
 */
extern void *stack_pop(stack_t *stack,size_t sz);
/**
 * @brief Destroy the stack
 *
 * @param stack:	The stack being destroyed
 */
extern void stack_destroy(stack_t *stack);

/** @} */
#endif
