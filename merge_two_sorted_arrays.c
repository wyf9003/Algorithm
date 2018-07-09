#include "stdio.h"
#include <stdlib.h>

// 合并两个排序的整数数组A和B变成一个新的数组。
// 给出A=[1,2,3,4]，B=[2,4,5,6]，返回 [1,2,2,3,4,4,5,6]
// 你能否优化你的算法，如果其中一个数组很大而另一个数组很小？

void main()
{
	int a[4] = {1,2,5,9};
	int b[10] = {2,3,4,5,7,8,11,15,30,34};
	int pointa = 0;
	int pointb = 0;
	int pointc = 0;
	int i = 0;
	
	int sizea = sizeof(a)/sizeof(int);
	int sizeb = sizeof(b)/sizeof(int);

	int* c = malloc(sizeof(a)+sizeof(b));
	
	while((pointa<sizea) && (pointb<sizeb))
	{
		if(a[pointa] <= b[pointb])
		{
			c[pointc] = a[pointa];
			pointa ++;
		}
		else
		{
			c[pointc] = b[pointb];
			pointb ++;
		}
		pointc ++;
	}
	if(pointa>=sizea)
	{
		while(pointb<sizeb)
		{
			c[pointc] = b[pointb];
			pointc ++;
			pointb ++;
		}
	}
	else if(pointb>=sizeb)
	{
		while(pointa<sizea)
		{
			c[pointc] = a[pointa];
			pointc ++;
			pointa ++;
		}
	}		
	
	for(i=0; i<sizea+sizeb; i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");
}