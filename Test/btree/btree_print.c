#include <data_structure/binary_tree.h>
#include <stdio.h>

bnode_t *root=NULL;

int main(void)
{
	root=bnode_new(4);
	bnode_add(root,1);
	bnode_add(root,5);
	bnode_add(root,4);
	bnode_add(root,4);
	bnode_add(root,6);
	bnode_print(root);
	bnode_delete(root);
	return 0;
}

