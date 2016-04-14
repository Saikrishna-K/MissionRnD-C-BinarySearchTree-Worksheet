/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void postNext(struct node *root, int *arr, int *index)
{
	if (root->left != NULL)		postNext(root->left, arr, index);

	if (root->right != NULL)	postNext(root->right, arr, index);

	arr[(*index)++] = root->data;

}

void preNext(struct node *root, int *arr, int *index)
{
	arr[(*index)++] = root->data;
	if (root->left != NULL)		preNext(root->left, arr, index);

	if (root->right != NULL)	preNext(root->right, arr, index);



}
void inNext(struct node *root, int *arr, int *index)
{
	if (root->left != NULL)		inNext(root->left, arr, index);
	arr[(*index)++] = root->data;
	if (root->right != NULL)	inNext(root->right, arr, index);



}


void inorder(struct node *root, int *arr){

	if (root == NULL || arr == NULL)
		return;

	else
	{
		int index = 0;
		inNext(root, arr, &index);
	}


}

void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;

	else
	{
		int index = 0;
		preNext(root, arr, &index);
	}
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr==NULL)
		return;

	else
	{
		int index = 0;
		postNext(root, arr, &index);
	}
}


