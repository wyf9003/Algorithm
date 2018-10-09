// 题干：
// 报数序列是指一个整照其中的整数的顺序进数序列，按行报数，得到下一个数。其前五项如下：
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 200

char* countAndSay(int n);

void main()
{
	char* p = countAndSay(1);
	printf("%s\n", p);
}

char* countAndSay(int n) 
{
	char* result[31] = {0};
	result[0] = (char*)malloc(10);
	memset(result[0], 0 ,10);
	
	result[0][0] = '1';
	
	int i = 1;
	while(i < n)
	{
		char temp = result[i-1][0];
		int j = 1;
		int result_n = 0;
		result[i] = (char*)malloc(LEN);
		memset(result[i], 0 ,LEN);
		int num = 1;
		int expansion_num = 1;	
		while(result[i-1][j] != '\0')
		{
			if(temp != result[i-1][j])
			{
				// 内存扩充
				if(result_n >= expansion_num*LEN)
				{
					expansion_num++;
					char* temp_p = (char*)malloc(LEN*expansion_num);
					memset(temp_p, 0, LEN*expansion_num);
					memcpy(temp_p, result[i], LEN*(expansion_num-1));
					result[i] = temp_p;
				}
				result[i][result_n++] = num+'0';
				result[i][result_n++] = temp;
				temp = result[i-1][j];
				num = 1;
			}
			else
			{
				num++;
			}
			j++;	
		}
		result[i][result_n++] = num+'0';
		result[i][result_n++] = temp;
		i++;
	}
	return result[i-1];
}


