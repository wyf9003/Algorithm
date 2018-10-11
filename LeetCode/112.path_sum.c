// 题干：
// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
// 这条路径上所有节点值相加等于目标和。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum);
bool cal_sum(struct TreeNode* root, int sum, int cal);

void main()
{
	
	
	
	printf("hello world\n");
}

bool hasPathSum(struct TreeNode* root, int sum) 
{
    return cal_sum(root, sum, 0);
}

bool cal_sum(struct TreeNode* root, int sum, int cal) 
{
    if(root != NULL)
	{
        bool check = false;

		if(root->left != NULL)
		{
			if((check==false)&&(cal_sum(root->left, sum, cal+root->val)==true))
            {
                check = true;
            }
		}
		if(root->right != NULL)
		{
			if((check==false)&&(cal_sum(root->right, sum, cal+root->val)==true))
            {
                check = true;
            }
		}    
        if((root->right == NULL)&&(root->left == NULL))
		{
            if(check ==false)
            {
               	if((cal+root->val) == sum)
                {
                    check = true;
                }
                else
                {

                    check = false;	
                } 
            }

		}
        return check;
	}
    else
    {
        return false;
    }
}
