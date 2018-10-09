#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2);

void main()
{
	struct ListNode l1_0;
	struct ListNode l1_1;
	struct ListNode l1_2;
	struct ListNode l1_3;
	
	struct ListNode* l1 = &l1_0;
	l1_0.val = 1;
	l1_0.next = &l1_1;
	l1_1.val = 2;
	l1_1.next = &l1_2;
	l1_2.val = 2;
	l1_2.next = &l1_3;
	l1_3.val = 4;
	l1_3.next = NULL;
	
	struct ListNode l2_0;
	struct ListNode l2_1;
	struct ListNode l2_2;
	struct ListNode l2_3;
	
	struct ListNode* l2 = &l2_0;
	l2_0.val = 1;
	l2_0.next = &l2_1;
	l2_1.val = 3;
	l2_1.next = &l2_2;
	l2_2.val = 3;
	l2_2.next = &l2_3;
	l2_3.val = 4;
	l2_3.next = NULL;
	
	struct ListNode* l3 = mergeTwoLists(l1, l2);
	while(l3 != NULL)
	{
		printf("%d ", l3->val);
		l3 = l3->next;
	}
	
	printf("\n");
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	if((l1 != NULL)&&(l2 != NULL))
	{
		// 选取第一个元素小的链表作为返回链表
		if(l1->val <= l2->val)
		{
			return merge(l1, l2);
		}
		else
		{
			return merge(l2, l1);
		}	
	}
	else if(l1 == NULL)
	{
		return l2;
	}
	else
	{
		return l1;
	}
}

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode* l1_temp = l1;
	struct ListNode* l2_temp = l2;
	
	while(l1_temp->next != NULL)
	{
		while((l2 != NULL)&&(l1_temp->next->val >= l2->val))
		{
			l2_temp = l2->next;
			l2->next = l1_temp->next;
			l1_temp->next = l2;
			l2 = l2_temp;
		}
		l1_temp = l1_temp->next;
	}
	l1_temp->next = l2;
	return l1;
}



