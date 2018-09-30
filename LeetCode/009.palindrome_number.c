#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(int x);

void main()
{
	int x = 100;
	printf("%d\n", isPalindrome(x));
}

int isPalindrome(int x) 
{
	int result = 0;
	int num = 0;
	
    if((x < 0)||((x%10 ==0)&&(x!=0)))
	{
		return 0;
	}
	else
	{
		while(result<x)
		{
			num = x%10;
			result = result*10 + num;
			x = x/10;
			printf("%d %d\n",x, result);
			if(result == x)
			{
				return 1;
			}
		}
		if((result/10) == x)
		{
			return 1;
		}
		return 0;
	}
}