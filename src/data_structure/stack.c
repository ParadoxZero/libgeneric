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

stStack* stCreateStack(size_t size){
    stStack *new_stack = malloc(sizeof(stStack));
    if(new_stack==NULL){
        st_errno = ST_ENOMEN;
        return NULL;
    }
    new_stack->list = stCreateList(size);
    if(new_stack->list==NULL){
        free(new_stack);
        st_errno = ST_ENOMEN;
        return NULL;
    }
    new_stack->stack_size = 0;
    return new_stack;
}

void stDeleteStack(stStack *stack){
    stDeleteList(stack->list);
    free(stack);
}


void * stGetStackTop(stStack *stack){
    if(stack == NULL){
        st_errno = ST_ENOITM;
        return NULL;
    }
    if(stack->stack_size == 0){
        st_errno = ST_EBUFUNDR;
        return NULL;
    }
    return stGetListItem(stack->list, stack->stack_size - 1);

}

int stPopStack(stStack *stack){
    if(stack == NULL){
        st_errno = ST_ENOITM;
        return -1;
    }
    if(stack->stack_size == 0){
        st_errno = ST_EBUFUNDR;
        return -1;
    }
    return stRemoveItemList(stack->list, 0);
}

int stPushStack(stStack *stack, void *value){
    if(stack == NULL){
        st_errno = ST_ENOITM;
        return -1;
    }
    return stAddListItemAt(stack->list, value,0);
}