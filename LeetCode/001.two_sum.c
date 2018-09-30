// 题干：
// 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
// 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
// 示例:
// 给定 nums = [2, 7, 11, 15], target = 9
// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* 用hash表实现，时间复杂度为O(n) */
#define HASH_MAX    20

typedef struct list
{
    int num;
    struct list* next;
}LIST;

void intput_hashtable(LIST* hasharray[], int num);
int search_hashtable(LIST* hasharray[], int num);
int* twoSum(int* nums, int numsSize, int target);

void main()
{
	int nums[3] = {3,2,4};
	int target = 6;
	int* answer = twoSum(nums, 3, target);
	int i = 0;
	for(i=0; i<3; i++)
	{
		printf("%d ", answer[i]);
	}
}

int* twoSum(int* nums, int numsSize, int target) 
{
    int i = 0, j=0;
    int* answer = malloc(sizeof(int)*numsSize);
	memset(answer, 0, sizeof(int)*numsSize);
    int answer_size = 0;
    
    LIST* hasharray[HASH_MAX] = {NULL};
	memset(hasharray, 0, sizeof(LIST*)*HASH_MAX);

    for(i=0; i<numsSize; i++)
    {
        intput_hashtable(hasharray, nums[i]);
    }
	
    for(i=0; i<numsSize; i++)
    {
        int searchnum = target-nums[i];
		
		if(searchnum == nums[i])
		{
			if(search_hashtable(hasharray, searchnum)%2 == 0) 
			{
				answer[answer_size++] = i;
			}
		}
		else
		{
			 if(search_hashtable(hasharray, searchnum) >= 1)
			{
				answer[answer_size++] = i;
			}
		}
    }
    return answer;
}

int hash(int num)
{
    return abs(num%HASH_MAX);    
}

void intput_hashtable(LIST* hasharray[], int num)
{
	LIST* new_node = (LIST*)malloc(sizeof(LIST));
    new_node->num = num;
    new_node->next = NULL;
	
    int i = hash(num);

    LIST* node = hasharray[i];
	if(hasharray[i] == NULL)
	{
		hasharray[i] = new_node;
	}
	else
	{
		while(node->next != NULL)
		{
			node = node->next;
		}
		node->next = new_node;
	}
}

int search_hashtable(LIST* hasharray[], int num)
{
    int i = hash(num);
    LIST* node = hasharray[i];
    int amount = 0;
	
	if(hasharray[i] == NULL)
	{
		amount = 0;
	}
	else
	{
		while(node != NULL)
		{
			if(node->num == num)
			{
				amount++;
			}
			node = node->next;
		}
	}
	return amount;
}
