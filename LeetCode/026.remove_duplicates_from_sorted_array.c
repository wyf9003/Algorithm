// 题干：
// 给定一个排序数组，你需要在原地删除重复出现的元素，
// 使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
// 不需要考虑数组中超出新长度后面的元素。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize);

void main()
{
	int nums[10] = {0,0,1,1,1,2,2,3,3,4};
	
	int size = removeDuplicates(nums, 10);
	int i =0;
	for(i=0; i<size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int removeDuplicates(int* nums, int numsSize) 
{
	if(numsSize != 0)
	{
		int i = 0,j = 0;
		for(i=1; i<numsSize; i++)
		{
			if(nums[j] != nums[i])
			{
				nums[++j] = nums[i];
			}
		}
		return ++j;
	}
	return 0;
}

