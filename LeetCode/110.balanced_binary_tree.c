// 题干：
// 给定一个二叉树，判断它是否是高度平衡的二叉树。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root);
int maxDepth(struct TreeNode* root, bool* check);

void main()
{
	
	printf("hello world\n");
}

int maxDepth(struct TreeNode* root, bool* check)
{
	int *check = 1;
	return maxDepth(root, &check);
}

int maxDepth(struct TreeNode* root, int* check) 
{
	if(root != NULL)
	{
		int left_result = maxDepth(root->left, check);
        int right_result = maxDepth(root->right, check);
        
		if((*check ==true)&&((abs(left_result-right_result))>1))
		{
			*check = false;
		}
		
        return (left_result>right_result)?left_result+1:right_result+1;
	}
	else
	{
		return 0;
	}
}

