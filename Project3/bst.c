#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "CMSC216_bst.h"

void changeLevel(bst*);
bst* minValue(bst*);


int dLev = 0;
int size = 0;
bst* prev = NULL;
bst* pMin = NULL;
struct BST_type
{
	char* data;
	int level;
	bst* left;
	bst* right;
};

int bst_create(bst** newTree)
{
	
	*newTree = (bst*)malloc(sizeof(bst));
	if(*newTree == NULL)
	{
		return -1;
	}
	(*newTree)->data = NULL;
	(*newTree)->left = NULL;
	(*newTree)->right = NULL;
	return 1;
		
}

/* 
 * insert the string value[] into the bst
 * return true if successful;
 * return false if the string already exists in the tree
 */
int bst_insert(bst** theTree, char* value)
{
	
	if (bst_find(theTree, value) > 0)
	{
		return -1;
	}
	if ((*theTree == NULL) || size == 0)
	{

		if (size == 0)
		{
			size++;
			dLev++;
			(*theTree)->data = value;
			(*theTree)->left = NULL;
			(*theTree)->right = NULL;
			(*theTree)->level = dLev;
			dLev = 0;
			return 1;
		}

		size++;
		dLev++;
		*theTree = (bst*)malloc(sizeof(bst));
		(*theTree)->data = value;
		(*theTree)->left = NULL;
		(*theTree)->right = NULL;
		(*theTree)->level = dLev;
		dLev = 0;
		return 1;
	}
	else if (strcmp(value, (*theTree)->data) < 0)
	{
		dLev++;
		bst_insert(&((*theTree)->left), value);
		return 1;
	}	
	else if (strcmp(value, (*theTree)->data) > 0)
	{
		dLev++;
		bst_insert(&((*theTree)->right), value);
		return 1;
	}


}

/*
 * find a particular string in the tree.
 *  return true if it is found;
 *   return false if it does not exist in the tree.
 *   */
int bst_find(bst** theTree, char* value)
{
	if (size == 0)
	{
		return -1;
	}

	else if (*theTree == NULL)
	{
		return -1;
	}
	else if (strcmp((*theTree)->data, value) == 0)
	{
		return 1;
	}
	else if (strcmp(value, (*theTree)->data) < 0)
	{
		return bst_find(&((*theTree)->left), value);
	}
	else if (strcmp(value, (*theTree)->data) > 0)
	{
		return bst_find(&((*theTree)->right), value);
	}


}

/*
 *  remove a particular string from the tree.
 *   return true if it is found (and deleted);
 *    return false if it was never in the tree;
 *     */
int bst_remove(bst** theTree, char* value)
{
	if (bst_find(theTree, value) < 0)
	{
		return -1;
	}

	if (strcmp(value, (*theTree)->data) == 0)
	{
		
		/*Case 1: Is a leaf*/
		if ((*theTree)->left == NULL && (*theTree)->right == NULL)
		{
			if (prev->left == *theTree)
			{
				prev->left = NULL;
				
			}
			else if (prev->right == *theTree)
			{
				prev->right = NULL;
			}
			
			free(*theTree);
			prev = NULL;
			size--;
		}
		/*Case 2: Has one child*/
		else if (((*theTree)->left == NULL && (*theTree)->right != NULL) || ((*theTree)->left != NULL && (*theTree)->right == NULL))
		{
			bst* hold = *theTree;
			if (prev->left == *theTree)
			{
				if ((*theTree)->left != NULL)
				{
					int tmpLevel = (*theTree)->level;
					prev->left = (*theTree)->left;
					changeLevel(prev->left);
					(*theTree)->level = tmpLevel;
					
				}
				else
				{
					int tmpLevel = (*theTree)->level;
					prev->left = (*theTree)->right;
					changeLevel(prev->left);
					(*theTree)->level = tmpLevel;
				}
				size--;
			}
			else if (prev->right == *theTree)
			{
				
				if ((*theTree)->left != NULL)
				{
					int tmpLevel = (*theTree)->level;
					prev->right = (*theTree)->left;
					changeLevel(prev->right);
					(*theTree)->level = tmpLevel;
				}
				else
				{
					int tmpLevel = (*theTree)->level;
					prev->right = (*theTree)->right;
					changeLevel(prev->right);
					(*theTree)->level = tmpLevel;
					
				}

				size--;
			}
			prev = NULL;
			free(hold);
		}
		/*Case 3: Two children*/
		else if ((*theTree)->left != NULL && (*theTree)->right != NULL)
		{
			bst* hold = *theTree;
			bst* min = minValue((*theTree)->right);
			int tmpLevel = (*theTree)->level;
			if (prev == NULL)
			{
				if (min->right == NULL)
				{
					if (pMin == NULL)
					{
						min->left = (*theTree)->left;
						
					}
					else
					{

						pMin->left = NULL;
						min->right = (*theTree)->right;
						min->left = (*theTree)->left;
					}

				}
				else
				{
					if (pMin == NULL)
					{
						changeLevel(min->right);
						min->left = (*theTree)->left;

					}
					else
					{
						changeLevel(min->right);
						pMin->left = min->right;
						min->right = (*theTree)->right;
						min->left = (*theTree)->left;
					}


				}
				
				min->level = tmpLevel;
				free(*theTree);
				*theTree = min;
			}
			else if (prev->left == *theTree)
			{
				if (min->right == NULL)
				{
					if (pMin == NULL)
					{						
						min->left = (*theTree)->left;
						prev->left = min;
						
					}
					else
					{
						
						pMin->left = NULL; 
						min->right = (*theTree)->right;
						min->left = (*theTree)->left;
						prev->left = min;
					}

				}
				else
				{
					if (pMin == NULL)
					{
						changeLevel(min->right);
						min->left = (*theTree)->left;
						prev->left = min;
						
					}
					else
					{
						changeLevel(min->right);
						pMin->left = min->right;						
						min->right = (*theTree)->right;
						min->left = (*theTree)->left;
						prev->left = min;					
					}
					

				}


				(prev->left)->level = tmpLevel;

				
				free(hold);
			}
			else if (prev->right == *theTree)
			{
				if (min->right == NULL)
				{
					if (pMin == NULL)
					{
						min->left = (*theTree)->left;
						prev->right = min;
					}
					else
					{
						pMin->left = NULL;
						min->right = (*theTree)->right;
						min->left = (*theTree)->left;
						prev->right = min;
					}
					
				}
				else
				{
					if (pMin == NULL)
					{
						changeLevel(min->right);
						min->left = (*theTree)->left;
						prev->right = min;
					}
					else
					{
						changeLevel(min->right);
						pMin->left = min->right;
						min->right = (*theTree)->right;
						min->left = (*theTree)->left;
						prev->right = min;
					}
				
				}

				(prev->right)->level = tmpLevel;
				/*free(*theTree)*/
			}
			prev = NULL;
			pMin = NULL;
		}
		
		return 1;
	}
	else if (strcmp(value, (*theTree)->data) < 0)
	{
		prev = *theTree;
		bst_remove(&((*theTree)->left), value);
		return 1;
	}
	else if (strcmp(value, (*theTree)->data) > 0)
	{
		prev = *theTree;
		bst_remove(&((*theTree)->right), value);
		return 1;
	}



}

bst* minValue(bst* tree)
{
	if (tree->left != NULL)
	{
		pMin = tree;
		return minValue(tree->left);
	}
	else
	{
		return tree;
	}

}

void changeLevel(bst* tree)
{
	if (tree == NULL)
	{
		return;
	}
		
	changeLevel(tree->left);

	(tree->level)--;

	changeLevel(tree->right);
	
}

void bst_display(bst** theTree)
{
	queue_type* queue = queue_new();
	bst* p;
	int clev = 1;
	
	printf("%s", (*theTree)->data);
	if ((*theTree)->left != NULL)
	{
	
		queue_enqueue(queue, ((*theTree)->left));
	
	}

	if ((*theTree)->right != NULL)
	{
		queue_enqueue(queue, ((*theTree)->right));
	}
	
	

	while(queue->size != 0)
	{
		
		p = queue_dequeue(queue);
		
		if (clev != p->level)
		{
			printf("\n");
			clev = p->level;
		}
		
		printf("%s ", p->data);
		
		if (p->left != NULL)
		{
			queue_enqueue(queue, (p->left));
		}

		if (p->right != NULL)
		{
			queue_enqueue(queue, (p->right));
		}
	}

}
/* destroy the tree and free up all memory*/
int bst_destroy(bst** theTree)
{
	
	
	if (*theTree == NULL)
	{
		return;
	}


	bst_destroy(&((*theTree)->left));

	bst_destroy(&((*theTree)->right));

	free(*theTree);
	return;
}
