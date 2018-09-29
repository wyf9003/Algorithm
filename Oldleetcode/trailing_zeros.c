#include "stdio.h"

void main()
{
	long long n = 1243214;
	long long tennum = 0;
	long long fivenum = 0;
	long long twonum = 0;
	long long zeronum = 0;
	long long data = n;
	
	
	// 这部分代码是参考网上的结果
	
	while(data > 0)
	{
		zeronum += data /5;
		data /= 5;
	}
	 

	// 下面的代码是个人思考的
	/*
	for(n; n>0; n--)
	{
		data = n;
		while(data%5 == 0)
		{
			data = data/5;
			fivenum ++;
		}
	}
	zeronum = fivenum;
	*/
	printf("%d\n", zeronum);
}