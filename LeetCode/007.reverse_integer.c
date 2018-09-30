// 题干：
// 给定一个 32 位有符号整数，将整数中的数字进行反转。
// 示例：
// 假设我们的环境只能存储 32 位有符号整数，
// 根据这个假设，如果反转后的整数溢出，则返回 0。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10
#define MAX_32		 2147483648
#define MIN_32		-2147483648

int reverse(int x);

void main()
{
	int x = 1563847412;
	x = reverse(x);
	printf("%d\n", x);
}

int reverse(int x) 
{
    unsigned int num[LEN] = {0};
	const unsigned int max[LEN] = {2,1,4,7,4,8,3,6,4,8};
    unsigned int i = 0;
	char check = 1;
	int result = 0;
    unsigned char len = 0;
	
    for(i=0; i<LEN; i++)
    {
        if((num[i] = x%10) == 0)
		{
			len ++;
			check = 0;
		}
		else
		{
			len = 0;
			check = 1;
		}
		x = x/10;
        printf("%d ",num[i]);
    }
	len = LEN- len;
    
	for(i=0; i<len; i++)
	{
		result = num[i]+result*10;
		
		if(check == 1)
		{
			if(abs(num[i]) > max[i])
			{
				return 0;
			}
			else if(abs(num[i]) < max[i])
			{
				check = 0;
			}
		}
	}
	return result;
}

