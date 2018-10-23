// 题干：
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
// 说明：本题中，我们将空字符串定义为有效的回文串。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char* s);

void main()
{
	char* s = "0P";
	
	printf("%d\n", isPalindrome(s));
}

int isPalindrome(char* s)
{
	int len = strlen(s);
	printf("%d\n", len);
	int i = 0;
	int j = len-1;
    for(i=0; i<len; i++)
	{
		if((*(s+i)>='A'&& *(s+i)<='Z') ||
			(*(s+i)>='a'&& *(s+i)<='z') ||
			(*(s+i)>='0'&& *(s+i)<='9') )
		{
			while(!((*(s+j)>='A'&& *(s+j)<='Z') ||
				      (*(s+j)>='a'&& *(s+j)<='z') ||
					  (*(s+j)>='0'&& *(s+j)<='9') ))
			{
				j--;
			}
			printf("%c %c\n", *(s+i), *(s+j));
			if( *(s+i) == *(s+j) ||
				!(*(s+j)>='0'&& *(s+j)<='9') && ((*(s+i)+'a'-'A') == *(s+j)||*(s+i) == (*(s+j)+'a'-'A')))
			{
				j--;
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}

