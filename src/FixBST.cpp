/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};




struct node * prev = NULL;  // To store the previous node value during inorder traversal.
int index = 0;// For index reference purpose for "arr".


void inOrder(struct node *root, struct node *arr[])  // Checking the misplaced nodes by inorder traversal.
{
	if (root->left != NULL) 	inOrder(root->left, arr);


	if (prev != NULL)
	if (index != 1){

		if (root->data < prev->data)
		{
			arr[index++] = prev;
			arr[index] = root;
		}
		else
		{
			prev = root;
		}
	}

	else if (index == 1)
	{
		if (root->data < prev->data){

			arr[index] = root;
			return;
		}

    }

	prev = root;

	if (root->right != NULL)	inOrder(root->right, arr);
}



void fix_bst(struct node *root){

	

	if (root == NULL)
		return;

	else
	{
		prev = NULL; index = 0;

		struct node *arr[2];// to store nodes to be exchanged

		inOrder(root, arr);
		int	i = arr[1]->data;
		arr[1]->data = arr[0]->data;
		arr[0]->data = i;


	}
}