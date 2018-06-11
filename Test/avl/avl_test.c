#include <generic/avl.h>
#include <generic/bst.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    gAVL *avl_tree = gAVLCreate(sizeof(int), gINT_COMPARE);

    //sorted array, worst case scenario for a bst
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 , 16};

    //numOfElements = total space in memory taken up by array / space taken by 1 element
    int numOfElementsInTree = sizeof(data) / sizeof(data[0]);

    //add data to avl tree
    for (int i = 0; i < numOfElementsInTree ; ++i){
        gAVLAdd(avl_tree, &data[i]);
    }

    avl_node_t *found = gAVLSearch(avl_tree, &data[3]);
    if (found == NULL) {
        fprintf(stderr, "%d: Node not found\n", data[3]);
        return 1;
    }

    //idealHeight = log base 2 of numOfElementsInTree, rounded up to nearest integer
    int idealHeight = ceil( log(numOfElementsInTree) / log(2) );

    printf("Ideal height of a tree with %d elements = %d\n" , numOfElementsInTree, (int)idealHeight);
    printf("Height of avl tree = %zu\n" , gAVLheight(avl_tree->root));//must be equal idealHeight or idealHeight + 1

    gAVLDelete(avl_tree);
    return 0;
}