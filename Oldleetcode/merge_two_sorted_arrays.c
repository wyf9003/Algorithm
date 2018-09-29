#include "stdio.h"
#include <stdlib.h>

// �ϲ������������������A��B���һ���µ����顣
// ����A=[1,2,3,4]��B=[2,4,5,6]������ [1,2,2,3,4,4,5,6]
// ���ܷ��Ż�����㷨���������һ������ܴ����һ�������С��

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