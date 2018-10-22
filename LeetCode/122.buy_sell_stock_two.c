// 题干：
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize);

void main()
{
	int prices[6] = {7,1,5,3,6,4};
	printf("%d \n", maxProfit(prices,6));
}

int maxProfit(int* prices, int pricesSize) 
{
    int min = *prices;
	int max = *prices;
	
	int sum = 0;

	int i = 0;
	for(i=1; i<pricesSize; i++)
	{
		if(prices[i] >= max)
		{
			max = prices[i];
		}
		else
		{
			sum += (max - min);
			printf("%d %d\n",min, max);
			min = prices[i];
			max = prices[i];
		}
	}
	sum += (max-min);
	
	return sum;
}