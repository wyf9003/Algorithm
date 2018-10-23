// 题干：
// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
// push(x) -- 将元素 x 推入栈中。
// pop() -- 删除栈顶的元素。
// top() -- 获取栈顶元素。
// getMin() -- 检索栈中的最小元素。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int* stack;
	int* sort_array;
	int num;
	int size;
}MinStack;

void main()
{
	
	
	
	printf("hello world\n");
}


/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) 
{
    MinStack* s = (MinStack* )malloc(sizeof(MinStack));
	s->stack = (int*)malloc(maxSize*sizeof(int));
	s->sort_array = (int*)malloc(maxSize*sizeof(int));
	s->num = 0;
	s->size = maxSize;
	
	return s;
}

void minStackPush(MinStack* obj, int x) 
{
	if(obj->num != obj->size)
	{
		*(obj->stack+obj->num) = x;
		int i = 0, j = 0;
		
		for(i=0; i<obj->num; i++)
		{
			if(x < *(obj->sort_array+i))
			{
				for(j=obj->num; j>i; j--)
				{
					*(obj->sort_array+j) = *(obj->sort_array+j-1);
				}		
				break;
			}
		}
        *(obj->sort_array+i) = x;
		(obj->num)++;
	}
}

void minStackPop(MinStack* obj) 
{
	if(obj->num != 0)
	{
		int i = 0, j=0;
		for(i=0; i<obj->num; i++)
		{
			if(*(obj->sort_array+i) == *(obj->stack+obj->num-1))
			{
				for(j=i; j<obj->num-1; j++)
				{
					*(obj->sort_array+j) = *(obj->sort_array+j+1);
				}
				break;
			}
		}
		(obj->num)--;
	}
}

int minStackTop(MinStack* obj) 
{
	if(obj->num !=0 )
	{
		return *(obj->stack+obj->num-1);
	}
}

int minStackGetMin(MinStack* obj) 
{
    return *(obj->sort_array);
}

void minStackFree(MinStack* obj) 
{
    free(obj->stack);
	free(obj->sort_array);
	free(obj);
}


