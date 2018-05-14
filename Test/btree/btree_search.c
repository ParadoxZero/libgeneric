#include <data_structure/binary_tree.h>
#include <stdio.h>

bnode_t *tree;
const int key=6;

int main(void)
{
	tree=bnode_new(5);
	bnode_add(tree,12);
	bnode_add(tree,1);
	bnode_add(tree,6);
	bnode_add(tree,4);
	bnode_add(tree,3);
	bnode_add(tree,6);
	bnode_add(tree,14);
	bnode_t *found=bnode_search(tree,key);
	if(found==NULL){
		fprintf(stderr,"%d: Node not found\n",key);
		return 1;
	}
	printf("Found %d with count of %lu\n",key,found->count);
	return 0;
}

