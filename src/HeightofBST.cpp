/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void next(struct node *root, int index, int *max)
{
	index++;

	if (root->left != NULL)  next(root->left, index, max);

	if (root->right != NULL) next(root->right, index, max);

	if (*max< index) *max = index;
	
}


int get_height(struct node *root){

	if (root == NULL) return 0;

	else{
		int index = 0, max = 1;
        next(root, index, &max);
		return max;
	   }

	
}


int Sum(struct node * root)
{
	if (root == NULL) return 0;

	return root->data + Sum(root->left) + Sum(root->right);
}



int get_left_subtree_sum(struct node *root){
	
	if (root == NULL) return -1;

	if (root->left == NULL) return 0;


	else
	{
	 struct node *temp = root->left;
	 return Sum(temp);
	}


}



int get_right_subtree_sum(struct node *root){
	if (root == NULL) return -1;

	if (root->right == NULL) return 0;


	else
	{
	 struct node *temp = root->right;
	 return Sum(temp);
	}
}

