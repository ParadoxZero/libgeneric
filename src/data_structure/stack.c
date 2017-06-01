/*
 *   MIT License
 *
 *   Copyright (c) 2017 Sidhin S Thomas
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

#include <data_structure/stack.h>

st_stack* st_stack_create(size_t size){
    st_stack *new_stack = malloc(sizeof(st_stack));
    if(new_stack==NULL){
        st_errno = ST_ENOMEN;
        return NULL;
    }
    new_stack->list = st_list_create(size);
    if(new_stack->list==NULL){
        free(new_stack);
        st_errno = ST_ENOMEN;
        return NULL;
    }
    new_stack->stack_size = 0;
    return new_stack;
}

void * st_stack_top(st_stack *stack){
    if(stack == NULL){
        st_errno = ST_ENOCTNR;
        return NULL;
    }
    if(stack->stack_size == 0){
        st_errno = ST_EBUFUNDR;
        return NULL;
    }
    return st_list_get(stack->list, stack->stack_size-1);

}

int st_stack_pop(st_stack *stack){
    if(stack == NULL){
        st_errno = ST_ENOCTNR;
        return -1;
    }
    if(stack->stack_size == 0){
        st_errno = ST_EBUFUNDR;
        return -1;
    }
    return st_list_remove(stack->list,stack->stack_size-1);
}

int st_stack_push(st_stack* stack, void *value){
    if(stack == NULL){
        st_errno = ST_ENOCTNR;
        return -1;
    }
    return st_list_add(stack->list,value);
}