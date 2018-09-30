// 题干：
// 罗马数字转整数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanToInt(char* s);
int judge(char s);

void main()
{
	char* str = "MCMXCIV";
	
	printf("%d\n", romanToInt(str));
}

int romanToInt(char* s) 
{
    char* chr = s;
	int divide[15];
	unsigned int i = 0;
	
	int result = 0;
	while(*(chr+i) != '\0')
	{
		printf("%c ", *(chr+i));
		divide[i] = judge(*(chr+i));
		result += divide[i];
		printf("%d ", divide[i]);
		if((i>=1)&&(divide[i-1] < divide[i]))
		{
			result -= 2*divide[i-1];
		}
		i++;
	}
	return result;
}

int judge(char s)
{
	int result = 0;
	switch(s)
	{
		case 'I':
			result = 1;
			break;
		case 'V':
			result = 5;
			break;
		case 'X':
			result = 10;
			break;
		case 'L':
			result = 50;
			break;
		case 'C':
			result = 100;
			break;
		case 'D':
			result = 500;
			break;
		case 'M':
			result = 1000;
			break;
		default:
			result = 0;
	}
	return result;
}

