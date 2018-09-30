// 题干：
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

int isValid(char* s);
int judge(char s);

void main()
{
	char* s = "]";
	printf("%d\n",isValid(s));
}

int isValid(char* s) 
{
    int* result = malloc(LEN*sizeof(int));
	memset(result, 0, sizeof(int)*LEN);
	int i = 0;	
	int temp = 0;	
	int result_num = 0;	
	
	result[0] = result_num;
	int expansion_num = 1;	
		
	while(*s!= '\0')
	{
		printf("s:%c ", *s);
		temp = judge(*s);
		printf("temp:%d ", temp);
		if(temp > 0)
		{
			result_num += temp;
			i++;
			if(i>=LEN*expansion_num)
			{
				expansion_num++;
				//printf("%d ", expansion_num);
				int* temp_p = malloc(LEN*expansion_num*sizeof(int));
				memset(temp_p, 0, LEN*expansion_num*sizeof(int));
				memcpy(temp_p, result, LEN*(expansion_num-1)*sizeof(int));
				result = temp_p;
				//printf("%s\n", result);
			}
			result[i] = result_num; 
			
			printf("i:%d result_num:%d ",i, result_num);
		}
		else if(temp < 0)
		{
			result_num += temp;
			if((i>0)&&(result_num == result[i-1]))
			{
				i--;
				printf("i:%d result_num:%d ",i, result_num);
			}
			else
			{
				return 0;
			}
		}
		s++;
		printf("\n");
	}
	if(result_num == 0)
	{
		return 1;
	}
	else
	{
		return 0;	
	}
}

int judge(char s)
{
	int result = 0;
	switch(s)
	{
		case '(':
			result = 1;
			break;
		case ')':
			result = -1;
			break;
		case '[':
			result = 2;
			break;
		case ']':
			result = -2;
			break;
		case '{':
			result = 3;
			break;
		case '}':
			result = -3;
			break;
		default:
			result = 0;
	}
	return result;
}



