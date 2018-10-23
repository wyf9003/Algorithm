// 题干：
// 给定一个链表，判断链表中是否有环。
// 你能否不使用额外空间解决此题？

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head);

void main()
{
	
	
	
	printf("hello world\n");
}

bool hasCycle(struct ListNode *head) 
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	
	while((slow !=NULL)&&(fast != NULL))
	{
		if((fast=fast->next) != NULL)
		{
			fast = fast->next;
		}
		else
		{
			return false;
		}
		slow = slow->next; 
		if(slow == fast)
		{
			return true;
		}
	}
	return false;

}




