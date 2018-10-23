// 题干：
// 给定一个正整数，返回它在 Excel 表中相对应的列名称。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int n);

void main()
{
	convertToTitle(900);
	
	
	printf("hello world\n");
}

char* convertToTitle(int n) 
{
	char* str = (char*)malloc(50);
	memset(str, 0 ,50);
	int i = 0,j=0;

    while(n != 0)
    {
		// 注意这个--n，
        *(str+i) = (--n)%26+'A';
        n = n/26;
        i++;
    }

    char temp = 0;
    for(j=0; j<i/2; j++)
    {
        temp = *(str+j);
        *(str+j) = *(str+i-1-j);
        *(str+i-1-j) = temp;
    }
    return str; 
}