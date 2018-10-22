// 题干：买卖股票的最佳时机
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
// 注意你不能在买入股票前卖出股票。

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
    int buy = *prices;
	int i = 0;
	int best = 0;
	for(i=0; i<pricesSize; i++)
	{
		int gap = prices[i]-buy;
		if(gap <= 0)
		{
			buy = prices[i];
		}
		else
		{
			if(gap > best)
			{
				best = gap;
			}
		}
	}
	return best;
}