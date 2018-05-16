/*
 *   MIT License
 *
 *   Copyright (c) 2017-2018 Sidhin S Thomas
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
/*
 * @file    stack.h
 *
 * @brief   Stack is a LIFO data structure implemented on top of @ref List.h
 *
 *
 */
#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include <data_structure/data_structure.h>
#include <data_structure/list.h>
/** @addtogroup stack
 * @{
 */
 /** @defgroup lstack Legacy
 * The stack implemented by Sidhin S Thomas and remains untested
 * @{
 */

/**
 * This structure represents a stack.
 * It contains all the information regarding the stack.
 */
typedef struct st_stack {
    stList *list;
    unsigned int stack_size;
} stStack ;

/**
 * Creates a stack, allocates necessary memories and returns the pointer.
 *
 *  @param itemSize:    The size of the items that will be stored within the stack
 *
 *  @return:            A pointer to the stack that was created.
 *                      May return 'NULL' in case of failure to allocate necessary memory.
 */
stStack* stCreateStack(size_t itemSize);

/*
 * Deletes a previously created stack and free associated memories
 *
 *  @param stack:       The stack to be deleted.
 *
 *  @return:            Nothing.
 */
void stDeleteStack(stStack *stack);

/*
 * Returns the data contained in the top of stack.
 *
 *  @param stack:       The stack whose top is required
 *
 *  @return:            A pointer to the location constaing the data.
 *                      he pointer should be casted to the type of the
 *                      data before being used.
 *                      May return 'NULL' in case of failure.
 *                      Check st_errno for reason.
 */
void * stGetStackTop(stStack *stack);

/*
 * Removes the top element of the stack.
 *
 *  @param stack:       The stack whose top is to be removed.
 *
 *  @return:            An integer representing the success or failure of operation.
 *                      ( 0) -> Success
 *                      (-1) -> Failed
 */
int stPopStack(stStack *stack);

/*
 * Pushed a data into the stack.
 *
 *  @param stack:       The stack where the data is to be pushed.
 *  @param item:        The pointer to the data to be pushed.
 *
 *  @return:            An integer representing the success or failure of operation.
 *                      ( 0) -> Success
 *                      (-1) -> Failed
 */
int stPushStack(stStack *stack, void *item);

/** @} */
/** @} */
#endif //DATA_STRUCTURE_STACK_H
