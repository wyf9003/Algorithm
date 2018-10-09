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
    int len = 0;
	int space_l = -1;
	if(s != NULL)
	{
		while(*(s+len) != '\0')
		{
			if(*(s+len) == ' ')
			{
				space_l = len;
				printf("%d\n", space_l);
			}	
			len++;
		}
	}
	
	printf("%d\n", len);
	if(len == 0)
	{
		return 0;
	}
	if(space_l != -1)
	{
		return len-space_l;
	}
	if(space_l == -1)
	{
		return len;
	}
	
}


