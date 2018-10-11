// 题干：
// 给定一个二叉树，返回其节点值自底向上的层次遍历。 
// 即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize);
int check_tree(struct TreeNode* root, int depth, int** returnarray, int* columnSizes);

//				 3
//			  /   \
//         9     20
//       /   \  /  \ 
//             15   7
//      \    / / \   \
//          

void main()
{
	struct TreeNode TreeNode_0;
	struct TreeNode TreeNode_1;
	struct TreeNode TreeNode_2;
	struct TreeNode TreeNode_3;
	struct TreeNode TreeNode_4;
	struct TreeNode TreeNode_5;
	struct TreeNode TreeNode_6;
	struct TreeNode TreeNode_7;
	struct TreeNode TreeNode_8;
	struct TreeNode TreeNode_9;
	struct TreeNode TreeNode_10;
	struct TreeNode TreeNode_11;
	
	TreeNode_0.val = 3;
	TreeNode_0.left = &TreeNode_1;
	TreeNode_0.right = &TreeNode_2;
	
	TreeNode_1.val = 9;
	TreeNode_1.left = NULL;
	TreeNode_1.right = NULL;
	
	TreeNode_2.val = 20;
	TreeNode_2.left = &TreeNode_5;
	TreeNode_2.right = &TreeNode_6;
	
	// TreeNode_3.val = 3;
	// TreeNode_3.left = NULL;
	// TreeNode_3.right = &TreeNode_7;
	
	// TreeNode_4.val = 4;
	// TreeNode_4.left = &TreeNode_8;
	// TreeNode_4.right = NULL;
	
	TreeNode_5.val = 15;
	TreeNode_5.left = NULL;
	TreeNode_5.right = NULL;
	
	TreeNode_6.val = 7;
	TreeNode_6.left = NULL;
	TreeNode_6.right = NULL;
	
	// TreeNode_7.val = 7;
	// TreeNode_7.left = NULL;
	// TreeNode_7.right = NULL;
	
	// TreeNode_8.val = 8;
	// TreeNode_8.left = NULL;
	// TreeNode_8.right = NULL;
	
	// TreeNode_9.val = 9;
	// TreeNode_9.left = NULL;
	// TreeNode_9.right = NULL;
	
	// TreeNode_10.val = 10;
	// TreeNode_10.left = NULL;
	// TreeNode_10.right = NULL;
	
	// TreeNode_11.val = 11;
	// TreeNode_11.left = NULL;
	// TreeNode_11.right = NULL;
	
	int* columnSizes = NULL;
	int returnSize = 0;
	int** returnarray = levelOrderBottom(&TreeNode_0, &columnSizes, &returnSize);
	
	int i=0,j=0;
	for(i=0; i<returnSize; i++)
	{
		for(j=0; j<columnSizes[i]; j++)
		{
			printf("%d ", returnarray[i][j]);
		}
		printf("\n");
	}
}

// 二叉树最大深度
#define BINARY_TREE_MAX_DEPTH		1000

// 二叉树每层最大保存数
#define BINARY_TREE_LAYER_MAX_NUM	200

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
    int** returnarray = (int**)malloc(BINARY_TREE_MAX_DEPTH*sizeof(int*));
	memset(returnarray, 0 , BINARY_TREE_MAX_DEPTH*sizeof(int*));
	int i = 0;
	for(i=0; i<BINARY_TREE_MAX_DEPTH; i++)
	{
		*(returnarray+i) = (int*)malloc(BINARY_TREE_LAYER_MAX_NUM*sizeof(int));
		memset(*(returnarray+i), 0 ,BINARY_TREE_LAYER_MAX_NUM*sizeof(int));
	}
	
	*columnSizes = (int*)malloc(BINARY_TREE_MAX_DEPTH*sizeof(int));
	memset(*columnSizes, 0, BINARY_TREE_MAX_DEPTH*sizeof(int));
	
	*returnSize = 0;
	if(root != NULL)
	{
		*returnSize = check_tree(root, *returnSize, returnarray, *columnSizes)+1;
	}
	
	int* temp = NULL;
	int temp_c = 0;
	for(i=0; i<*returnSize/2; i++)
	{
		temp = *(returnarray+*returnSize-i-1);
		*(returnarray+*returnSize-i-1) = *(returnarray+i);
		*(returnarray+i)= temp;
		
		temp_c = *(*columnSizes+*returnSize-i-1);
		*(*columnSizes+*returnSize-i-1) = *(*columnSizes+i);
		*(*columnSizes+i) = temp_c;
	}
	return returnarray;
}

int check_tree(struct TreeNode* root, int depth, int** returnarray, int* columnSizes)
{
	int left_depth = depth;
	int right_depth = depth;
	
	if(root!= NULL)
	{
		returnarray[depth][columnSizes[depth]++] = root->val;
	}
	if(root->left != NULL)
	{
		left_depth++;
		left_depth = check_tree(root->left, left_depth, returnarray, columnSizes);
	}
	if(root->right != NULL)
	{
		right_depth++;
		right_depth = check_tree(root->right, right_depth, returnarray, columnSizes);
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



