// 题干：
// 实现 int sqrt(int x) 函数。
// 计算并返回 x 的平方根，其中 x 是非负整数。
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int mySqrt(int x);

void main()
{
	int x= 10;
	
	printf("%d\n", mySqrt(x));
}

int mySqrt(int x) 
{
    int result = (int)sqrt((double)x);
    printf("%lf ", result);
	return result;
}