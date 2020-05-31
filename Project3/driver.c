#include <stdio.h>
#include "CMSC216_bst.h"

void main()
{
	bst* tmp = NULL;
	bst** tree = &tmp;
	bst_create(tree);

	bst_insert(tree, "p");
	bst_insert(tree, "r");
	bst_insert(tree, "d");
	bst_insert(tree, "b");
	bst_insert(tree, "h");
	bst_insert(tree, "q");
	bst_insert(tree, "v");
	bst_insert(tree, "a");
	bst_insert(tree, "c");
	bst_insert(tree, "i");
	bst_insert(tree, "z");
	bst_insert(tree, "t");
	bst_insert(tree, "s");
	bst_insert(tree, "u");
	bst_insert(tree, "w");
	bst_insert(tree, "y");
	

	printf("My test Binary Search Tree is below. Every row shows the nodes/elements on that level.\n\n");
	bst_display(tree);
	printf("\n");


}
