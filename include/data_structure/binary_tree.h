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
 * @file	binary_tree.h
 *
 * @brief	A tree data structure where one node has at most two children
 */
#ifndef	DATA_STRUCTURE_BINARY_TREE
#define	DATA_STRUCTURE_BINARY_TREE
/** @defgroup btree Binary Tree
 *
 * Binary Tree is a data structure where one node has at most two children
 *
 * @{
 */

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

/** @brief Add number to a tree
 *
 * If the number is smaller than a node, store it to the left one.
 * If it is greater, store it to the right one.
 * If it is equal, increase the count
 *
 * @param root:	The root node of the tree
 * @param num:	Number being added
 *
 * @return	Node where the number is inserted
 */
extern void btree_add(bnode_t *root,int num);

/** @brief Delete a tree
 *
 * It uses recursive mechanism to delete the sub-node of the tree
 *
 * @param root:	Root node of the tree being removed
 */
extern void btree_delete(bnode_t *root);

/** @brief Search a number in the tree
 *
 * @param root:	Root node of the tree
 * @param num:	Number being searched
 */
extern void btree_search(bnode_t *node,int num);

/** @} */
#endif

