// 题干：
// 给定一个二叉树，检查它是否是镜像对称的。
// 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool check_tree(struct TreeNode* p, struct TreeNode* q);
bool isSymmetric(struct TreeNode* root);
 
void main()
{
	
	
	printf("hello world\n");
}


bool isSymmetric(struct TreeNode* root) 
{
    if(root != NULL)
    {
        return check_tree(root->left, root->right);
    }
    else
    {
        return true;
    }
}

bool check_tree(struct TreeNode* p, struct TreeNode* q)
{
	int outside_result = false;
	int inside_result = false;
	int middle_result = false;
	
	if((p != NULL) &&(q != NULL))
	{
		outside_result = check_tree(p->left, q->right);
		inside_result = check_tree(p->right, q->left);
		if(p->val == q->val)
		{
			middle_result = true;
		}
		
		if((outside_result == true)&&(inside_result == true)&&(middle_result == true))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if((p == NULL) &&(q == NULL))
	{
		return true;
	}
	else
	{
		return false;
	}
}













