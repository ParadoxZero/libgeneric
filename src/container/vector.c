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

#include <generic/vector.h>
#include <assert.h>
#include <string.h>

void gVectorCreate(struct gVector *vector, size_t size) {
    assert(vector != NULL);
    assert(size > 0);
    vector->alloc = VECTOR_DEFAULT_ELEMS * size;
    vector->n = 0;
    vector->elems = malloc(vector->alloc);
    vector->elem_sz = size;
}

void gVectorDestroy(struct gVector *vector) {
    free(vector->elems);
    vector->elems = NULL;
    vector->n = 0;
    vector->elem_sz = 0;
    vector->alloc = 0;
}

void gVectorPushBack(struct gVector *vector, void *val) {
    assert(vector != NULL);
    assert(val != NULL);
    size_t size = (vector->elem_sz) * (vector->n);
    char *ptr = (char *) vector->elems;
    /* If the required size is more than alloc, double the allocated space */
    if (size >= vector->alloc) {
        gVectorResize(vector, size);
    }
    /* Copy the value to the end of the vector */
    memcpy(ptr + size, val, vector->elem_sz);
    vector->n++;    // Increase the logical size
}

void *gVectorPopBack(struct gVector *vector) {
    assert(vector != NULL);
    if (vector->n < 1) {
        return NULL;
    }
    void *ptr = gVectorBack(vector);
    vector->n--;
    return ptr;
}

void gVectorResize(gVector *vector, size_t new_size) {
    assert(vector != NULL);
    size_t tmp = new_size * vector->elem_sz;
    vector->alloc = tmp;
    vector->n = new_size;
    vector->elems = realloc(vector->elems, tmp);
}

void *gVectorFront(gVector *vector) {
    assert(vector != NULL);
    return vector->elems;
}

void *gVectorBack(gVector *vector) {
    if (vector->n == 0) {
        return vector->elems;
    }
    return gVectorItemAt(vector, vector->n - 1);
}

void *gVectorItemAt(gVector *vector, size_t index) {
    assert(vector != NULL);
    size_t size = index * vector->elem_sz;
    char *ptr = (char *) vector->elems;
    return ptr + size;
}

void *gVectorSet(gVector *vector, size_t pos, void *val) {
    void *ptr = gVectorItemAt(vector, pos);
    memcpy(ptr, val, vector->elem_sz);
    return ptr;
}

void *gVectorInsert(gVector *vector, size_t pos, void *val) {
    assert(vector != NULL);
    char *ptr = (char *) gVectorItemAt(vector, pos);
    char *ptr2 = (char *) gVectorBack(vector);
    size_t size = ptr2 - ptr;
    gVectorPushBack(vector, ptr2);    // Put the last value at the back
    memmove(ptr + vector->elem_sz, ptr, size);
    gVectorSet(vector, pos, val);
    return ptr;
}

