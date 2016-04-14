/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};



void height(struct node *root, int index, int *max)
{
	index++;
	
	if (root->left != NULL)  height(root->left, index, max);

	if (root->right != NULL) height(root->right, index, max);
	
    if (*max< index) *max = index;

}


void nextLevel(struct node *root, int *arr, int *index, int level, int curlevel)
{
	if (curlevel == level){// if specified level met , copy that value into the array
		arr[(*index)++] = root->data;		
		return;
	}

	if (root->right != NULL)	nextLevel(root->right, arr, index, level, curlevel + 1);
	if (root->left != NULL)		nextLevel(root->left, arr, index, level, curlevel + 1);

}




int* BSTRighttoLeftRows(struct node* root)
{

	if (root == NULL) return NULL;

   int index = 0, maxLevel = 1, *arr, i, size = 1;
	
   height(root, index, &maxLevel);// First find the max height of the tree
	
	if (maxLevel > 1){ // count the max number of nodes for a tree of height calculated above

	    for (i = 0; i <maxLevel; i++)
		{
			size *= 2;
		}
		size--;
    }

	
	arr = (int *)calloc(size, sizeof(int)); // allocate memory for maximum number of nodes for a tree of height calculated above


	index = 0;

	// for each level, add the node values to array
	for (i = 0; i < maxLevel; i++)
	{
		nextLevel(root, arr, &index, i, 0);
	}
	arr = (int *)realloc(arr,sizeof(int)*index);

	return arr;
}
