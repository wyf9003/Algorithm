#include "stdio.h"


// ����һ���ַ�����һ��ƫ����������ƫ������ת�ַ���(����������ת)
// ��������ԭ����ת��ʹ��O(1)�Ķ���ռ�


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