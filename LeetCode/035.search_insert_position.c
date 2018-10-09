// 题干：
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
// 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 你可以假设数组中无重复元素。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchInsert(int* nums, int numsSize, int target);

void main()
{
	int nums[4] = {1,3,5,6};
	int target = 5;
	
	int position = searchInsert(nums, 4, target);
	
	printf("%d\n", position);
}

int searchInsert(int* nums, int numsSize, int target) 
{
	int i = 0;
	for(i=0; i<numsSize; i++)
	{
		if(target <= nums[i])
		{
			return i;
		}
	}
	return numsSize;
}

/* int searchInsert(int* nums, int numsSize, int target) 
{
	if(numsSize >=2)
	{
		int middle = numsSize/2;
		// 左边
		if(nums[middle-1] >= target)
		{
			searchInsert(nums, middle, target);
		}
		else
		{
			searchInsert((nums+middle), numsSize-middle, target);
		}
	}
	else
	{
		return nums[0];
	}
} */







