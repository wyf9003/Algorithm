// 题干：
// 实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，
// 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
// 如果不存在，则返回  -1。


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle);

void main()
{
	char* haystack = "hello";
	char* needle = "ll";
	
	int location = strStr(haystack, needle);
	
	printf("%d\n", location);
}

int strStr(char* haystack, char* needle) 
{
    char* ph = haystack;
	char* pn = needle;
	int i = 0,j=0;
	
	if((haystack != NULL)&&(needle != NULL))
	{
		if(*needle == '\0')
		{
			return 0;
		}
		
		while(*(ph+i) != '\0')
		{
			char check = 0;
			j = 0;
			while(*(pn+j) != '\0')
			{
				if(*(ph+i+j) != *(pn+j))
				{
					check = 1;
					break;
				}
				j++;
			}
			if(check == 0)
			{
				return i;
			}
            i++;
		}
		return -1;
	}
	return 0;
}

