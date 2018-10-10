// 题干：
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
// 注意：给定 n 是一个正整数。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int climbStairs(int n);
int combination(int m, int n);

void main()
{
	int i = 0;
	for(i=0; i<30; i++)
	{
		printf("%d:%d\n",i, climbStairs(i));
	}
}

int climbStairs(int n) 
{
    int sum = 0;
	int i = 0;
	for(i=0; i<=n/2; i++)
	{
 		int j = 0;
		long long numerator = 1;		// 分子
		long long denominator = 1;	// 分母
		for(j=0; j<i; j++)
		{
			numerator *= (n-i-j);
			denominator *= (i-j);
		}
		sum += (numerator/denominator);
	}
	return sum;
}


