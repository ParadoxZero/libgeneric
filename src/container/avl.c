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

#include <generic/avl.h>
#include <string.h>

/**
 * Function: createNode
 * --------------------
 * Allocates and initializes a AVL node.
 *
 * @param item           The data item to be stored in the node
 * @param itemSize       The size of data item
 *
 * @return               The created node.
 *                       Will return NULL in case of failure
 */

static avl_node_t* createNode(void *item, size_t itemSize);

/**
 * Function: addNode
 * -----------------
 * This recursive function will add the given node to a avl tree.
 *
 * @param root          The avl tree root
 * @param node          Node to be added
 * @param isGreater     The function that will compare the values of nodes of avl tree
 *
 * @return              Pointer to the root of avl tree
 */

static avl_node_t* addNode(avl_node_t *root, avl_node_t *node, gDataCompare isGreater);

/**
 * Function: clearTree
 * -------------------
 * This function will recursively clear ( free ) a tree.
 *
 * @param node      Root node of tree to be cleared.
 */

static void cleargAVL(avl_node_t *node);

/**
 * Function: searchTree
 * --------------------
 * Search the avl tree recursively for the given data.
 *
 * @param avl_tree          The avl tree to be searched.
 * @param current_root      The root of subtree being searched
 * @param data              Data to be searched
 *
 * @return                  Pointer to the node containing the data.
 *                          NULL in case not found.
 */

static avl_node_t* searchgAVL(gAVL *avl_tree, avl_node_t *current_root, void *data);

/*
 * Rebalancing functions prototypes specific to AVL.
 */

/**
 * Function: max
 * --------------------
 * Returns the max of two integers
 *
 * @param x          		first number
 * @param y      			second number
 *
 * @return                  the larger of the two
 *
 * NOTE: not specific to avl but is required by gAVLheight function
 */

static int max(int x, int y);

/**
 * Function: leftRotate
 * --------------------
 * Left rotation of avl tree
 *
 * @param  avl_tree         pointer to avl tree
 * @param  x				pointer to node which acts as pivot to rotation
 *
 */

static void leftRotate(gAVL *avl_tree, avl_node_t *x);

/**
 * Function: rightRotate
 * --------------------
 * Right rotation of avl tree
 *
 * @param  avl_tree         pointer to avl tree
 * @param  x				pointer to node which acts as pivot to rotation
 *
 */

static void rightRotate(gAVL *avl_tree, avl_node_t *x);

/**
 * Function: rebalance
 * --------------------
 * One of the properties of avl tree is that is has height of ideally (log(2)(n))
 * where n is the number of nodes in tree. 
 * Avl tree thus consists of subtrees each of which are not too left heavy
 * or too right heavy.
 * To prevent the tree from being heavier on one side the tree is "rebalanced"
 * each time a new node is inserted into the tree.
 * There are four different cases to deal with which can be better visualized here:
 * https://en.wikipedia.org/wiki/Tree_rotation#/media/File:Tree_Rebalancing.gif
 * For more information about tree rotation view the wikipedia page about "Tree rotation"
 *
 * @param  avl_tree         pointer to avl tree
 * @param  x				pointer to node which acts as pivot to rotation
 *
 */

static void rebalance(gAVL* avl_tree, avl_node_t* node);

/*  ------------------------------- *
 *
 *  The API implementations follow.
 *
 *  ------------------------------- */

gAVL* gAVLCreate(size_t elementSize, gDataCompare comparator) {
    gAVL *avl_tree = malloc(sizeof(gAVL));
    if (avl_tree == NULL){
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    avl_tree->root = NULL;
    avl_tree->elementSize = elementSize;
    avl_tree->isGreater = comparator;
    return avl_tree;
}

int gAVLAdd(gAVL *avl_tree, void *item){
    if (avl_tree == NULL){
        gErrorCode = G_EINVLD;
        return gErrorCode;
    }
    avl_node_t *node = createNode(item, avl_tree->elementSize);
    if (avl_tree->root == NULL) {
        avl_tree->root = node;
        if (avl_tree->root == NULL){
            return gErrorCode;
        }
        return 0;
    }
    avl_tree->root = addNode(avl_tree->root, node, avl_tree->isGreater);
    rebalance(avl_tree , node);
    return 0;
}

void gAVLDelete(gAVL *avl_tree) {
    if (avl_tree == NULL) {
        return;
    }
    if (avl_tree->root != NULL){
        cleargAVL(avl_tree->root);
    }
    free(avl_tree);
}

avl_node_t *gAVLSearch(gAVL *avl_tree, void *data) {
    if (avl_tree == NULL) {
        gErrorCode = G_ENOITM;
        return NULL;
    }

    return searchgAVL(avl_tree, avl_tree->root, data);    // Nothing found, return a null pointer

}

/*  --------------------------------- *
 *
 *  Utility function implementations.
 *
 *  --------------------------------- */

static avl_node_t* createNode(void *item, size_t itemSize){
    avl_node_t *node = malloc(sizeof(avl_node_t));
    if(node == NULL){
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->data = malloc(itemSize);
    if (node->data == NULL){
        free(node);
        gErrorCode = G_ENOMEN;
        return NULL;
    }
    memcpy(node->data, item, itemSize);
    return node;
}

static avl_node_t* addNode(avl_node_t* root, avl_node_t *node, gDataCompare isGreater){
    if (!isGreater(root->data,node->data)){
        if(root->right == NULL) {
            root->right = node;
            node->parent = root;
        }
        else {
            root->right = addNode(root->right, node, isGreater);
        }
    }
    else {
        if(root->left == NULL){
            root->left = node;
            node->parent = root;
        }
        else {
            root->left = addNode(root->left, node, isGreater);
        }
    }
    return root;
}

static void cleargAVL(avl_node_t *node){
    if(node->left!=NULL)
        cleargAVL(node->left);
    if(node->right != NULL)
        cleargAVL(node->right);
    free(node);
}

static avl_node_t* searchgAVL(gAVL *avl_tree, avl_node_t *current_root, void *data){
    if (current_root == NULL)
        return NULL;
    if (memcmp(current_root->data, data, avl_tree->elementSize)==0){
        return current_root;
    }
    else if (!avl_tree->isGreater(current_root->data, data)){
        return searchgAVL(avl_tree, current_root->right, data);
    }
    else {
        return searchgAVL(avl_tree, current_root->left, data);
    }
}

static int max(int x, int y)
{
    return x > y? x: y;
}

size_t gAVLheight(avl_node_t *root)
{
    if(root == NULL)
        return 0;
    return 1 + max( gAVLheight(root->left), gAVLheight(root->right));
}

static void leftRotate(gAVL *avl_tree, avl_node_t *x)
{
    avl_node_t *y = x->right;
    y->parent = x->parent;

    if( y->parent == NULL)
    {
        avl_tree->root = y;
    }
    else
    {
        if( y->parent->left == x)
            y->parent->left = y;
        else if( y->parent->right == x)
            y->parent->right = y;
    }
    x->right = y->left;

    if( x->right != NULL)
    {
        x->right->parent = x;
    }
    y->left = x;
    x->parent = y;
}

static void rightRotate(gAVL *avl_tree, avl_node_t *x)
{
    avl_node_t *y = x->left;
    y->parent = x->parent;

    if( y->parent == NULL)
    {
        avl_tree->root = y;
    }
    else
    {
        if( y->parent->left == x)
            y->parent->left = y;
        else if( y->parent->right == x)
            y->parent->right = y;
    }
    x->left = y->right;

    if( x->right != NULL)
    {
        x->right->parent = x;
    }
    y->right = x;
    x->parent = y;
}

static void rebalance(gAVL* avl_tree, avl_node_t* node)
{
    while ( node != NULL)
    {
        if( gAVLheight(node->left) >= 2 + gAVLheight(node->right))
        {
            if (gAVLheight(node->left->left) >= gAVLheight(node->left->right))
            {
                rightRotate( avl_tree, node);
            }
            else
            {
                leftRotate( avl_tree, node->left);
                rightRotate( avl_tree, node);
            }
        }
        else if( gAVLheight(node->right) >= 2 + gAVLheight(node->left))
        {
            if (gAVLheight(node->right->right) >= gAVLheight(node->right->left))
            {
                leftRotate( avl_tree, node);
            }
            else
            {
                rightRotate( avl_tree, node->right);
                leftRotate( avl_tree, node);
            }
        }
        node = node->parent;
    }
}
