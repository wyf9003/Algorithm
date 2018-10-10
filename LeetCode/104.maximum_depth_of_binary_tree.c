// 题干：
// 给定一个二叉树，找出其最大深度。
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
// 说明: 叶子节点是指没有子节点的节点。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int check_tree(struct TreeNode* root, int depth);

void main()
{
	
	
	
	printf("hello world\n");
}


int maxDepth(struct TreeNode* root) 
{
	int depth = 1;
	
    if(root != NULL)
	{
		return  check_tree(root, depth);
	}
	else
	{
		return 0;
	}
}

int check_tree(struct TreeNode* root, int depth)
{
	int left_depth = depth;
	int right_depth = depth;
	
	if(root->left != NULL)
	{
		left_depth++;
		left_depth = check_tree(root->left, left_depth);
	}
	if(root->right != NULL)
	{
		right_depth++;
		right_depth = check_tree(root->right, right_depth);
	}		
			
	if(left_depth >= right_depth)
	{
		return left_depth;
	}
	else
	{
		return right_depth;
	}
}




