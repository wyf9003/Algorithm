// 题干：
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
// 在杨辉三角中，每个数是它左上方和右上方的数的和。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generate(int numRows, int** columnSizes);

void main()
{
	int* columnSizes = NULL;
	int** pascal = generate(1, &columnSizes);
	int i = 0, j=0;
	for(i=0; i<1; i++)
	{
		printf("%d:", columnSizes[i]);
		for(j=0; j<columnSizes[i]; j++)
		{
			printf("%d ", *(*(pascal+i)+j));
		}
		printf("\n");
	}
	printf("hello world\n");
}

int** generate(int numRows, int** columnSizes) 
{
	if(numRows == 0)
    {
        return NULL;
    }
	
	int** pascal = (int**)malloc(numRows*sizeof(int*));
	int i = 0;
	for(i=0; i<numRows; i++)
	{
		*(pascal+i) = (int*)malloc((i+1)*sizeof(int));
		memset(*(pascal+i), 0, (i+1)*sizeof(int));
	}
	
    *columnSizes = (int*)malloc(numRows*sizeof(int));
	memset(*columnSizes, 0, numRows*sizeof(int));
	*(*pascal) = 1;
	*(*columnSizes) = 1;
	
	printf("check\n");

	for(i=1; i<numRows; i++)
	{
		int j = 1;
		*(*(pascal+i)) = 1;
		for(j=1; j<i; j++)
		{
			*(*(pascal+i)+j) = *(*(pascal+i-1)+j-1)+*(*(pascal+i-1)+j);
		}
		*(*(pascal+i)+j) = 1;
		*(*columnSizes+i) = i+1;
	}
	return pascal;
}


