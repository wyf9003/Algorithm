#include "stdio.h"


// 给定一个字符串和一个偏移量，根据偏移量旋转字符串(从左向右旋转)
// 在数组上原地旋转，使用O(1)的额外空间


void main()
{
	char str[7] = "abcdefg"; 
	int offset = 5;
	int i = 0;
	int j = 0;
	char temp;
	
	for(i=0; i<offset; i++)
	{
		temp = str[6];
		for(j=6; j>0; j--)
		{
			str[j] = str[j-1];
		}
		str[0] = temp;
	}
	for(i=0; i<7; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
}