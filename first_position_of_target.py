# 给定一个排序的整数数组（升序）和一个要查找的整数target
# 用O(logn)的时间查找到target第一次出现的下标（从0开始）
# 如果target不存在于数组中，返回-1

# 如果数组中的整数个数超过了2^32，你的算法是否会出错？

import sys
 
sys.setrecursionlimit(1000000) #例如这里设置为一百万

class Solution:
	def search(self, nums, target, begin, end):
		middle = int((begin+end)/2);
		
		if end-begin>1:
			if(nums[middle] > target):
				end = middle;
				return self.search(nums, target,begin,end);
			elif(nums[middle] < target):
				begin = middle;
				return self.search(nums, target,begin ,end);
			else:
				return middle;
		else:
			if nums[begin]==target:
				return begin;
			elif nums[end] == target:
				return end;
			else:
				return -1;
			
	def binarySearch(self, nums, target):
		first = self.search(nums, target, 0, len(nums)-1);
		if first != -1:
			while nums[first]==target :
				first = first - 1;
			return first+1;
		else:
			return -1;

nums = [4,5,9,9,12,13,14,15,15,18];
target = 10;

so = Solution();

first = so.binarySearch(nums, target);

print(first);




