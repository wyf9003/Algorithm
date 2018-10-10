// 题干：
// 给定两个二叉树，编写一个函数来检验它们是否相同。
// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int isSameTree(struct TreeNode* p, struct TreeNode* q);

void main()
{
	
	
	
	printf("hello world\n");
}

int isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
	int left_result = 0;
	int right_result = 0;
	int middle_result = 0;
	
	if((p != NULL) &&(q != NULL))
	{
		left_result = isSameTree(p->left, q->left);
		right_result = isSameTree(p->right, q->right);
		if(p->val == q->val)
		{
			middle_result = 1;
		}
		
		if((left_result == 1)&&(right_result == 1)&&(middle_result == 1))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if((p == NULL) &&(q == NULL))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


