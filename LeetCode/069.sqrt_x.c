// 题干：
// 实现 int sqrt(int x) 函数。
// 计算并返回 x 的平方根，其中 x 是非负整数。
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mySqrt(int x);

void main()
{
	int x= 2147483647;
	
	printf("%d\n", mySqrt(x));
}

int mySqrt(int x) 
{
	if(x == 0)
	{
		return 0;
	}
	if(x < 4)
	{
		return 1;
	}
	
	int middle = x/2+2;
	int i = 0;
	int result = 0;
	for(i=0; i<middle; i++)
	{
		long long square = (long long )i*(long long)i;
		if(square > (long long)x)
		{
			printf("%d\n", i);
			result = i-1;
			break;
		}
		else if(square == x)
		{
			result = i;
			break;
		}			
	}
	return result;
	
}