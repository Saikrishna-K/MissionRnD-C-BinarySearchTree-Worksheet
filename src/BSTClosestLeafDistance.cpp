/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

// Global declarations

bool minflag = false, flag = false;
int min,level,distance;


void minHeight(struct node *node, int index) // To find minimum distace from given  node to leaf
{

	if (node->left != NULL)  minHeight(node->left, index + 1);

	if (node->right != NULL)  minHeight(node->right, index + 1);

	if (minflag == false && node->left == NULL &&node->right == NULL)
	{
		minflag = true;
		min = index;
	}

	else if (min > index && node->left == NULL &&node->right == NULL)	
		    min = index;

}




void pathToNode(struct node *node, struct node*temp, int index)// This function traverse from root to given temp node. 
{
	int a = 0, b = 0;
	if (node == NULL) return;

	if (node == temp)
	{ 
		minflag = false;
		minHeight(node, level++);
		distance = min;
		flag = true;
		return;
	}


	if (flag == false)
	{
		pathToNode(node->left, temp, index + 1);

		if (flag == false)
			pathToNode(node->right, temp, index + 1);
	}

	if (flag == true)
	{
		minflag = false;
		minHeight(node, level++);
		if (distance > min) distance = min;
		return;
	}

}




int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;

	int index = 0;
	flag = false;
	level = 0;
	pathToNode(root, temp, index + 1);
	return distance;

}