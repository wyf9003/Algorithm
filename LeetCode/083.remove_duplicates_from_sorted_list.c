// 题干：
// 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head);

void main()
{
	struct ListNode node_0;
	struct ListNode node_1;
	struct ListNode node_2;
	struct ListNode node_3;
	struct ListNode node_4;
	struct ListNode node_5;
	struct ListNode node_6;
	struct ListNode node_7;
	
	node_0.val = 1;
	node_0.next = &node_1;
	node_1.val = 1;
	node_1.next = &node_2;
	node_2.val = 2;
	node_2.next = &node_3;
	node_3.val = 2;
	node_3.next = &node_4;
	node_4.val = 3;
	node_4.next = &node_5;
	node_5.val = 4;
	node_5.next = &node_6;
	node_6.val = 4;
	node_6.next = NULL;
	
	
	struct ListNode* temp = deleteDuplicates(&node_0);
	while(temp != NULL)
	{
		printf("%d ", temp->val);
		temp = temp ->next;
	}
}

struct ListNode* deleteDuplicates(struct ListNode* head) 
{
	if(head != NULL)
	{
		struct ListNode* front = head;
		struct ListNode* previous = head->next;
		
		while(previous != NULL)
		{
			if(front->val == previous->val)
			{
				front->next = previous->next;
				previous = front->next;
			}
			else
			{
				front = previous;
				previous = previous->next;
			}
		}
	}
	return head;
}



