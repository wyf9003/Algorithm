#include "stdio.h"

void main()
{
	long long n = 1243214;
	long long tennum = 0;
	long long fivenum = 0;
	long long twonum = 0;
	long long zeronum = 0;
	long long data = n;
	
	
	// �ⲿ�ִ����ǲο����ϵĽ��
	
	while(data > 0)
	{
		zeronum += data /5;
		data /= 5;
	}
	 

	// ����Ĵ����Ǹ���˼����
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