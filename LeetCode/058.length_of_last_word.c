// 题干：
// 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
// 如果不存在最后一个单词，请返回 0 。
// 说明：一个单词是指由字母组成，但不包含任何空格的字符串。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s);

void main()
{
	
	char* p = "a";
	
	printf("%d\n", lengthOfLastWord(p));
}

int lengthOfLastWord(char* s) 
{
    int num = 0;
	int temp = 0;
	if(s != NULL)
	{
		while(*s != '\0')
		{
			if(*s == ' ')
			{
				if(num != 0)
				{
					temp = num;
				}
				num = 0;
			}
			else
			{
				num ++;
			}
			s++;
		}
	}
	if(num == 0)
	{
		num = temp;
	}
	return num;
}


