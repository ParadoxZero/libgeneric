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

 // TODO: Make major changes
/**
 * @file	bst.h
 *
 * @brief	A tree data structure where one node has at most two children with left < root < right.
 */

#ifndef	DATA_STRUCTURE_BINARY_TREE
#define	DATA_STRUCTURE_BINARY_TREE

#include <stddef.h>
#include <stdlib.h>


/** @brief Binary Tree data structure
 *
 * Assuming the members are read-only to users
 */
typedef struct bnode {
	/** @brief Count of the same value */
	size_t count;
	/** @brief Value of the current node */
	int value;
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

/** @brief Create a node in binary tree
 *
 * @param num:	Value of the new node
 *
 * @return	Pointer to the new node
 */
extern bnode_t *bnode_new(int num);

/** @brief Add number to a tree
 *
 * If the number is smaller than a node, store it to the left one.
 * If it is greater, store it to the right one.
 * If it is equal, increase the count
 * This function recursively finds the accurate node
 *
 * @param node:	The root node of the tree
 * @param num:	Number being added
 *
 * @return	Node where the number is inserted
 */
extern bnode_t *bnode_add(bnode_t *node,int num);

/** @brief Delete a tree
 *
 * It uses recursive mechanism to delete the sub-node of the tree
 *
 * @param node:	Root node of the tree being removed
 */
extern void bnode_delete(bnode_t *node);

/** @brief Search a number in the tree
 *
 * @param node:	Root node of the tree
 * @param num:	Number being searched
 *
 * @return	Node containing the found number
 */
extern bnode_t *bnode_search(bnode_t *node, const int num);



#endif

