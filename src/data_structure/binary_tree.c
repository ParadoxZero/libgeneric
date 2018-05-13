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

#include <data_structure/binary_tree.h>
#include <malloc.h>
#include <assert.h>

bnode_t *bnode_new(int num)
{
	bnode_t *node=(bnode_t*)malloc(sizeof(bnode_t));
	node->value=num;
	node->count=1;
	node->left=node->right=NULL;	// No left or right nodes
	return node;
}

bnode_t *bnode_add(bnode_t *node,int num)
{
	if(node==NULL){
		return bnode_new(num);
	}
	if(node->value==num){
		node->count++;
		return node;
	}
	if(node->value>num){
		if(!node->left){
			node->left=bnode_new(num);
			return node->left;
		}
		return bnode_add(node->left,num);
	}else{
		if(!node->right){
			node->right=bnode_new(num);
			return node->right;
		}
		return bnode_add(node->right,num);
	}
	return NULL;	// Failure
}

void bnode_delete(bnode_t *node)
{
	if(node==NULL){
		return;
	}
	if(node->left!=NULL){
		bnode_delete(node->left);
		node->left=NULL;
	}
	if(node->right!=NULL){
		bnode_delete(node->right);
		node->right=NULL;
	}
	free(node);
}

bnode_t *bnode_search(bnode_t *node,const int num)
{
	bnode_t *ret=NULL;
	if(node==NULL){
		return NULL;
	}
//	printf("Searching in %lu x %d\n",node->count,node->value);
	if(node->value==num){
		return node;
	}
	if(node->value>num){
		return bnode_search(node->left,num);
	}
	if(node->value<num){
		return bnode_search(node->right,num);
	}
	return NULL;	// Nothing found, return a null pointer

}

void bnode_print(bnode_t *node)
{
	if(node->left){
		bnode_print(node->left);
	}
	if(node->right){
		bnode_print(node->right);
	}
	printf("%10lu x %10d\n",node->count,node->value);
}

