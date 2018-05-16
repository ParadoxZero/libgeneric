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

#include <generic/bst.h>
#include <string.h>

/*
 * Utility functions specific to BST.
 */

/**
 * Function: createNode
 * --------------------
 * Allocates and initializes a BST node.
 *
 * @param item           The data item to be stored in the node
 * @param itemSize       The size of data item
 *
 * @return               The created node.
 *                       Will return NULL in case of failure
 */
static bnode_t* createNode(void *item, size_t itemSize);

/**
 * Function: addNode
 * -----------------
 * This recursive function will add the given node to a bst.
 *
 * @param root          The bst root
 * @param node          Node to be added
 * @param isGreater     The function that will compare the values of nodes of bst
 *
 * @return              Pointer to the root of bst
 */
static bnode_t* addNode(bnode_t* root, bnode_t *node, gDataCompare isGreater);

/**
 * Function: clearTree
 * -------------------
 * This function will recursively clear ( free ) a tree.
 *
 * @param node      Root node of tree to be cleared.
 */
static void clearTree(bnode_t *node);

/**
 * Function: searchTree
 * --------------------
 * Search the bst recursively for the given data.
 *
 * @param bst               The bst to be searched.
 * @param current_root      The root of subtree being searched
 * @param data              Data to be searched
 *
 * @return                  Pointer to the node containing the data.
 *                          NULL in case not found.
 */
static bnode_t* searchTree(gBST *bst, bnode_t *current_root, void *data);


/*  ------------------------------- *
 *
 *  The API implementations follow.
 *
 *  ------------------------------- */

gBST* gBSTCreate(size_t elementSize, gDataCompare comparator) {
    gBST *bst = malloc(sizeof(gBST));
    if (bst == NULL){
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    bst->root = NULL;
    bst->elementSize = elementSize;
    bst->isGreater = comparator;
    return bst;
}

int gBSTAdd(gBST *bst, void *item) {
    if (bst==NULL){
        gErrorCode = G_EINVLD;
        return gErrorCode;
    }
    bnode_t *node = createNode(item, bst->elementSize);
    if (bst->root == NULL) {
        bst->root = node;
        if (bst->root == NULL){
            return gErrorCode;
        }
        return 0;
    }
    bst->root = addNode(bst->root, node, bst->isGreater);
    return 0;
}

void gBSTDelete(gBST *bst) {
    if (bst == NULL) {
        return;
    }
    if (bst->root != NULL){
        clearTree(bst->root);
    }
    free(bst);
}

bnode_t *gBSTSearch(gBST *bst, void *data) {
    if (bst == NULL) {
        gErrorCode = G_ENOITM;
        return NULL;
    }

    return searchTree(bst, bst->root, data);    // Nothing found, return a null pointer

}

/*  --------------------------------- *
 *
 *  Utility function implementations.
 *
 *  --------------------------------- */

static bnode_t* createNode(void *item, size_t itemSize){
    bnode_t *node = malloc(sizeof(bnode_t));
    if(node == NULL){
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    node->data = malloc(itemSize);
    if (node->data == NULL){
        free(node);
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    memcpy(node->data, item, itemSize);
    return node;
}

static bnode_t* addNode(bnode_t* root, bnode_t *node, gDataCompare isGreater){
    if (!isGreater(root->data,node->data)){
        if(root->right == NULL) {
            root->right = node;
        }
        else {
            root->right = addNode(root->right, node, isGreater);
        }
    }
    else {
        if(root->left == NULL){
            root->left = node;
        }
        else {
            root->left = addNode(root->left, node, isGreater);
        }
    }
    return root;
}

static void clearTree(bnode_t *node){
    if(node->left!=NULL)
        clearTree(node->left);
    if(node->right != NULL)
        clearTree(node->right);
    free(node);
}

static bnode_t* searchTree(gBST *bst, bnode_t *current_root, void *data){
    if (current_root == NULL)
        return NULL;
    if (memcmp(current_root->data, data, bst->elementSize)==0){
        return current_root;
    }
    else if (!bst->isGreater(current_root->data, data)){
        return searchTree(bst, current_root->right, data);
    }
    else {
        return searchTree(bst, current_root->left, data);
    }
}