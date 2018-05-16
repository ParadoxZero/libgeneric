/*
 *   MIT License
 *
 *   Copyright (c) 2018 Travor Liu
 *   Copyright (c) 2018 Sidhin S Thomas
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
 * @file	bst.h
 *
 * @brief	A tree data structure where one node has at most two children with left < root < right.
 */

#ifndef	DATA_STRUCTURE_BINARY_TREE
#define	DATA_STRUCTURE_BINARY_TREE

#include <stddef.h>
#include <stdlib.h>

#include <generic.h>
#include <generic/utils.h>


/** @brief Binary Tree data structure
 *
 * Assuming the members are read-only to users
 */
typedef struct bnode {
	/** @brief Data of the current node */
	void* data;
	/** @brief Left node
	 *
	 * Every number in left node is less than the current one
	 */
	struct bnode *left;
	/** @brief Right node
	 *
	 * Every number in the right is greater than the current
	 */
	struct bnode *right;
} bnode_t;

typedef struct gBST{
    bnode_t *root;
    gDataCompare isGreater;
    size_t elementSize;
} gBST;

/**
 * Function: gBSTCreate
 * --------------------
 * Create a node in binary search tree
 *
 * @param elementSize   The size of data to be stored.
 * @param comparator    The function to be used to compare the
 *                      elements
 *
 * @return	            Pointer to the new BST
 *                      will return NULL in case of failure
 */
gBST* gBSTCreate(size_t elementSize, gDataCompare comparator);

/**
 * Function: gBSTAdd
 * -----------------
 * Add element to the tree
 *
 * @param bst   The tree where the item is to be added.
 * @param item  The item to be added
 *
 * @return      status code of operation
 *              (0) if success, error code in case of failure.
 */
int gBSTAdd(gBST *bst, void *item);

/**
 * Function: gBSTDelete
 * --------------------
 * Delete a tree
 *
 *
 * @param bst:	BST that's being deleted.
 */
void gBSTDelete(gBST *bst);

/**
 * Function: gBSTSearch
 * --------------------
 * Search an item in the tree
 *
 * @param bst       The bst to be searched
 * @param data      The item to be searched
 *
 * @return	Node containing the found number
 */
bnode_t *gBSTSearch(gBST *bst, void *data);



#endif

