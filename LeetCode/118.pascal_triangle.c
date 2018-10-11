// 题干：
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
// 在杨辉三角中，每个数是它左上方和右上方的数的和。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generate(int numRows, int** columnSizes);

void main()
{
	generate();
	printf("hello world\n");
}

int** generate(int numRows, int** columnSizes) 
{
	int** pascal = (int**)malloc(numRows*sizeof(int*));
	int i = 0;
	for(i=0; i<numRows; i++)
	{
		*(pascal+i) = malloc((i+1)*sizeof(int));	
	}
	
    *columnSizes = (int*)malloc(numRows*sizeof(int));
	**pascal = 1;
	*(*pascal+1) = 1;
	*((*pascal+1)+1) = 1;
	columnSizes[0] = 1;
	columnSizes[1] = 2;
	
	int j = 1;
	for(i=2; i<numRows; i++)
	{
		for(j=1; j<numRows-1; j++)
		{
			*((*pascal+i)+j) = *((*pascal+i-1)+j-1)+*((*pascal+i-1)+j+1)
		}
		columnSizes[i] = i+1;
	}
}