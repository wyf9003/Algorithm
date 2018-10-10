// 题干：
// 给定两个二进制字符串，返回他们的和（用二进制表示）。
// 输入为非空字符串且只包含数字 1 和 0。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b);
char* add(char* max, int len_max, char* min, int len_min);

void main()
{
	char* a = "0";
	char* b = "0";
	
	printf("%s\n", addBinary(a, b));
}

char* addBinary(char* a, char* b) 
{
	int len_a = strlen(a);
	int len_b = strlen(b);
	
	char* max = NULL; 
	char* min = NULL;
	int len_max = 0; 
	int len_min = 0;
	
	if(len_a >= len_b)
	{
		max = a;
		len_max = len_a;
		min = b;
		len_min = len_b;
	}
	else
	{
		max = b;
		len_max = len_b;
		min = a;
		len_min = len_a;
	}
	
	int sum_size = len_max+2;
	
	char* sum = (char*)malloc(sum_size);
	memset(sum, 0, sum_size);
	
	int carry = 0;
	int i = 0;
	for(i=1; i<=len_max; i++)
	{
		if(len_min-i < 0)
		{
			sum[sum_size-i-1] = max[len_max-i]-'0'+carry;
		}
		else
		{
			sum[sum_size-i-1] = max[len_max-i]+min[len_min-i]-'0'-'0'+carry;
		}
		printf("%d:", sum_size-i);
		if(sum[sum_size-i-1] >= 2)
		{
			carry = 1;
			sum[sum_size-i-1] = sum[sum_size-i-1]-2+'0';
		}
		else
		{
			carry = 0;
			sum[sum_size-i-1] += '0';
		}
		printf("%c ", sum[sum_size-i-1]);
	}
	if(carry == 1)
	{
		sum[0] = '1';
	}
	else
	{
		return &sum[1];
	}
	
	return sum;
}







