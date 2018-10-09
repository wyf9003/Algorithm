// 题干：
// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

void main()
{
	int nums[3] = {1,2,3}; 
	int new_size = 0;
	int* new_nums = plusOne(nums, 3, &new_size);
	
	int i=0;
	for(i=0; i<new_size; i++)
	{
		printf("%d ", new_nums[i]);
	}
	
	printf("\n");
}

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	int i = 0;
	int carry = 1;
	int* new_digits = malloc((digitsSize+1)*sizeof(int));
	memset(new_digits, 0, (digitsSize+1)*sizeof(int));

	for(i=digitsSize-1; i>=0; i--)
	{
		if(carry == 1)
		{
			if(digits[i] == 9)
			{
				carry = 1;
				new_digits[i+1] = 0;
			}
			else
			{
				carry = 0;
				new_digits[i+1] = digits[i]+1;
			}
		}
		else
		{
			new_digits[i+1] = digits[i];
		}
		(*returnSize)++;
	}
	if(carry == 1)
	{
		new_digits[0] = 1;
		(*returnSize)++;
	}
	else
	{
		for(i=0; i<digitsSize; i++)
		{
			new_digits[i] = new_digits[i+1];
		}
	}
	return new_digits;	
}


