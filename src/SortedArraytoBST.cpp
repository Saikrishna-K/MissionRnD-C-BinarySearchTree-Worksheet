/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node *createNode(int *arr, int index)
{

	struct node* temp = (struct node*)calloc(1,sizeof(struct node));
	temp->data = arr[index];
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}




struct node* addNode(int *arr, int left, int right)
{
	if (left <= right)
	{
		struct node* temp = NULL;
		int mid = (left + right) / 2;
		temp = createNode(arr, mid);
		
		temp->left = addNode(arr, left, mid - 1);
		temp->right = addNode(arr, mid + 1, right);

		return temp;
	}
	return NULL;
}






struct node * convert_array_to_bst(int *arr, int len){

	if (arr == NULL) return NULL;

	else
	{
		struct node*temp = NULL;
		int mid = (0 + len - 1) / 2;
		temp = createNode(arr, mid);
		temp->left = addNode(arr, 0, mid - 1);
		temp->right = addNode(arr, mid + 1, len - 1);
		
		return temp;

	}


}