#include <generic/bst.h>
#include <stdio.h>


int main(void) {
    gBST *bst = gBSTCreate(sizeof(int), gINT_COMPARE);
    int data[] = {12,1,6,4,3,6,14};
    for (int i=0; i<7; ++i){
        gBSTAdd(bst,&data[i]);
    }
    bnode_t *found = gBSTSearch(bst, &data[3]);
    if (found == NULL) {
        fprintf(stderr, "%d: Node not found\n", data[3]);
        return 1;
    }
    printf("Found %d\n", data[3]);

    gBSTDelete(bst);
    return 0;
}

