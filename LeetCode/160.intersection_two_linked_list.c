// 题干：
// 编写一个程序，找到两个单链表相交的起始节点。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode 
{
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

void main()
{
	
	
	
	printf("hello world\n");
}

// 先搜索两个链表的长度，再从两个链表从后向前数，长度相同的最长位置开始比较，如果相等则返回
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    if((headA != NULL)&&(headB != NULL))
    {
        int sizeA = 0;
        int sizeB = 0;
        struct ListNode* nodeA = headA;
        struct ListNode* nodeB = headB;
        while(nodeA != NULL)
        {
            sizeA++;
            nodeA = nodeA->next;
        }
        while(nodeB != NULL)
        {
            sizeB++;
            nodeB = nodeB->next;
        }
        printf("%d %d\n", sizeA, sizeB);

        nodeA = headA;
        nodeB = headB;

        int i = 0;
        if(sizeA > sizeB)
        {
            for(i=0; i<(sizeA-sizeB); i++)
            {
                nodeA = nodeA->next;
            }
        }
        else
        {
            for(i=0; i<(sizeB-sizeA); i++)
            {
                nodeB = nodeB->next;
            }
        }

        while((nodeA != nodeB) &&(nodeA != NULL) &&(nodeB != NULL))
        {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return nodeA;
    }
    else
    {
        return NULL;
    }
}



