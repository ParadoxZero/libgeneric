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

#include <generic/lstack.h>

gLinkedStack *gLinkedStackCreate(size_t size) {
    gLinkedStack *new_stack = malloc(sizeof(gLinkedStack));
    if (new_stack == NULL) {
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    new_stack->list = gListCreate(size);
    if (new_stack->list == NULL) {
        free(new_stack);
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    new_stack->stack_size = 0;
    return new_stack;
}

void gLinkedStackDelete(gLinkedStack *stack) {
    gListDelete(stack->list);
    free(stack);
}


void *gLinkedStackTop(gLinkedStack *stack) {
    if (stack == NULL) {
        gErrorCode = G_ENOITM;
        return NULL;
    }
    if (stack->stack_size == 0) {
        gErrorCode = G_EBUFUNDR;
        return NULL;
    }
    return gListGetItem(stack->list, stack->stack_size - 1);

}

int gLinkedStackPop(gLinkedStack *stack) {
    if (stack == NULL) {
        gErrorCode = G_ENOITM;
        return -1;
    }
    if (stack->stack_size == 0) {
        gErrorCode = G_EBUFUNDR;
        return -1;
    }
    return gListRemoveItem(stack->list, 0);
}

int gLinkedStackPush(gLinkedStack *stack, void *value) {
    if (stack == NULL) {
        gErrorCode = G_ENOITM;
        return -1;
    }
    return gListAddItemAt(stack->list, value, 0);
}