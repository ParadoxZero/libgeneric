/*
 *   MIT License
 *
 *   Copyright (c) 2018 Ali Moussa
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or suavlantial portions of the Software.
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
 * @file	avl.h
 *
 * @brief	A tree data structure where one node has at most two children with left < root < right.
 * Tree also rebalances itself when a new node is added thus it is almost complete.
 */

#ifndef LIBGENERIC_AVL_H
#define LIBGENERIC_AVL_H

#include <stddef.h>
#include <stdlib.h>

#include <generic.h>
#include <generic/utils.h>

/** @brief AVL binary tree data structure
 *
 * Assuming the members are read-only to users
 */
typedef struct avl_node {
    /** @brief Data of the current node */
    void* data;
    /** @brief Left node
     *
     * Every number in left node is less than the current one
     */
    struct avl_node *left;
    /** @brief Right node
     *
     * Every number in the right is greater than the current
     */
    struct avl_node *right;
    /** @brief Parent node
     *
     * Pointer to parent node, number in root could be less than or greater than current one
     * depending on whether current node is the parent's left node or right node respectively
     */
    struct avl_node *parent;

} avl_node_t;

typedef struct {
    avl_node_t *root;
    gDataCompare isGreater;
    size_t elementSize;
} gAVL;

/**
 * Function: gAVLCreate
 * --------------------
 * Create a node in avl binary search tree
 *
 * @param elementSize   The size of data to be stored.
 * @param comparator    The function to be used to compare the
 *                      elements
 *
 * @return	            Pointer to the new avl tree
 *                      will return NULL in case of failure
 */
gAVL* gAVLCreate(size_t elementSize, gDataCompare comparator);

/**
 * Function: gAVLAdd
 * -----------------
 * Add element to the tree
 *
 * @param avl_tree   The tree where the item is to be added.
 * @param item  The item to be added
 *
 * @return      status code of operation
 *              (0) if success, error code in case of failure.
 */
int gAVLAdd(gAVL *avl_tree, void *item);

/**
 * Function: gAVLDelete
 * --------------------
 * Delete a tree
 *
 *
 * @param avl:	AVL tree that's being deleted.
 */
void gAVLDelete(gAVL *avl_tree);

/**
 * Function: gAVLSearch
 * --------------------
 * Search an item in the tree
 *
 * @param avl_tree  The avl_tree to be searched
 * @param data      The item to be searched
 *
 * @return	Node containing the found number
 */
avl_node_t *gAVLSearch(gAVL *avl_tree, void *data);

/**
 * Function: gAVLheight
 * --------------------
 * Returns height of the AVL tree. If n elements were added to the tree, height should be lg(n) or lg(n) + 1.
 *
 * @param root       node you want to compute its longest simple path downward ex: int heightOfTree = gAVLheight(avl_tree->root);
 *
 * @return	height of the tree as unsigned integer
 */

size_t gAVLheight(avl_node_t *root);

#endif //LIBGENERIC_AVL_H
