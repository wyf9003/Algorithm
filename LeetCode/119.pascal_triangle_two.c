// 题干：
// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
// 你可以优化你的算法到 O(k) 空间复杂度吗？

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getRow(int rowIndex, int* returnSize);
int search(int num);

void main()
{
	int returnSize = 0;
	int* p = getRow(3, &returnSize);
	
	
	printf("hello world\n");
}

int* getRow(int rowIndex, int* returnSize) 
{
	*returnSize = rowIndex+1;
    int* pascal = (int*)malloc((rowIndex+1)*sizeof(int));
	int i = 0;
	*pascal = 1;
	for(i=1; i<rowIndex; i++)
	{
		*(pascal+i) = search(rowIndex, i);
		
	}
	*(pascal+rowIndex-1) = 1;
	return pascal;
}

int search(int row, int num)
{
	if(num == 0)
	{
		return 1;
	}
	if(num == row)
	{
		return 1;
	}
	if(row == 0)
	{
		return 1;
	}
	return search(row-1, num-1)+search(row-1, num);
}




