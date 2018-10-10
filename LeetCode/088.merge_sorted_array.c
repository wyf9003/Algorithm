// 题干：
// 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
// 说明:
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int m, int* nums2, int n);

void main()
{
	int nums1[6] = {4,0,0,0,0,0};
	int nums2[5] = {1,2,3,5,6};
	merge(nums1, 1, nums2, 5);
	int i = 0;
	for(i=0; i<6; i++)
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");
}

// 不使用额外的空间
void merge(int* nums1, int m, int* nums2, int n) 
{
    int i = 0;
	int j = 0;
	int k = 0;
	int post = 0;
	
	while(1)
	{
		if(j >= n)
		{
			break;
		}
		if(i >= m)
		{
			while(j<n)
			{
				nums1[i+j] = nums2[j];
				j++;
			}
			break;
		}
		if(nums1[i+post] >= nums2[j])
		{
			for(k=m+post; k>i+post; k--)
			{
				nums1[k] = nums1[k-1];
			}
			nums1[i+post] = nums2[j];
			j++;
			post++;
		}
		else
		{
			i++;
		}
		
		printf("\n");
	}
}

