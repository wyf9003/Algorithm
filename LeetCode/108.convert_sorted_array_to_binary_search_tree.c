// 题干：
// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize);

void main()
{
	int nums[5] = {-10,-3,0,5,9};
	sortedArrayToBST(nums, 5);
	
	printf("\n");
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	
	if(numsSize == 0)
	{
		return NULL;
	}
	else
	{
		int middle = numsSize/2;
		root->val = nums[middle];
		root->left = sortedArrayToBST(nums, middle);
		root->right = sortedArrayToBST(nums+middle+1, numsSize-middle-1);
	}
	return root;
}




