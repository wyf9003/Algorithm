// 题干：
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
// 找出那个只出现了一次的元素。
// 你的算法应该具有线性时间复杂度

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int singleNumber(int* nums, int numsSize);

void main()
{
	
	
	
	printf("hello world\n");
}

// 这个方案不是自己想出来的，利用了相同数字异或运算为0；任何数字与0异或还为数字本身的特点。
int singleNumber(int* nums, int numsSize) 
{
	int num = 0;
    int i = 0;
	for(i=0; i<numsSize; i++)
	{
		num = num ^ nums[i];
	}
	return num;
}


