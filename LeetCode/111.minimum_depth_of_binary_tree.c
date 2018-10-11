// 题干：
// 给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
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

int minDepth(struct TreeNode* root);

void main()
{
	
	
	
	printf("hello world\n");
}


int minDepth(struct TreeNode* root) 
{
    if(root != NULL)
	{
		int left_result = minDepth(root->left)+1;
        int right_result = minDepth(root->right)+1;
        
        if(left_result == 1)
        {
            return right_result;
        }
        else if(right_result == 1)
        {
            return left_result;
        }
        else
        {
            return (left_result>right_result)?right_result:left_result;
        }
	}
	else
	{
		return 0;
	}
}