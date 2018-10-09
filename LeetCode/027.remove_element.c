// 题干：
// 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val);

void main()
{
	int nums[10] = {0,0,1,1,1,2,2,3,3,4};
	
	int size = removeElement(nums, 10, 1);
	int i =0;
	for(i=0; i<size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int removeElement(int* nums, int numsSize, int val) 
{
    if(numsSize != 0)
	{
		int i = 0,j = 0;
		for(i=0; i<numsSize; i++)
		{
			if(nums[i] != val)
			{
				nums[j++] = nums[i];
			}
		}
		return j;
	}
	return 0;
}

