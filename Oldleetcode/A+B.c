#include "stdio.h"

void main()
{
	int a = 342;
	int b = 234;
	int sum = 0;
	int tempsum = 0;
	int tempa = 0;
	int tempb = 0;
	int flag = 0;
	int tempflag = 0;
	int i = 0;
	
	// printf("Please enter a and b:");
	// scanf("%d %d", &a, &b);
	
	if(a&b == 0)
	{
		sum = a|b;
	}
	else
	{
		while(!(a==0 && b==0))
		{
			tempa = a&(1<<i);
			tempb = b&(1<<i);
			printf("tempa:%x tempb:%x flag:%x ", tempa, tempb,flag);
			tempsum = tempa ^ flag;
			tempflag = (tempa & flag)<<1;
			
			if(tempflag == 0)
			{
				flag = (tempsum & tempb)<<1;
			}
			else
			{
				flag = 1<<(i+1);
			}
			tempsum = tempsum ^ tempb;
			printf("tempsum:%x  ", tempsum);
			a = a&(~(1<<i));
			b = b&(~(1<<i));
			// sum = sum>>1;
			sum |= tempsum;
			printf("sum:%x\n", sum);
			tempsum = 0;
			i++;
		}
		if(flag == (1<<i))
		{
			sum |= (1<<i);
		}
		//sum = sum << i;
	}
	printf("%d\n", sum);
}
