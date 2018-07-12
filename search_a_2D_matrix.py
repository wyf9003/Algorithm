# 描述
# 写出一个高效的算法来搜索 m × n矩阵中的值。
# 这个矩阵具有以下特性：
# 每行中的整数从左到右是排序的。
# 每行的第一个数大于上一行的最后一个整数。

# 样例
# [
# 	[1, 3, 5, 7],
# 	[10, 11, 16, 20],
# 	[23, 30, 34, 50]
# ]
# 给出 target = 3，返回 true

# 挑战
# O(log(n) + log(m)) 时间复杂度

class Solution:
	
	def searchrank(self, nums, target, begin, end):
		middle = int((begin+end)/2);
		
		if end-begin>1:
			if(nums[middle] > target):
				end = middle;
				return self.searchrank(nums, target,begin,end);
			elif(nums[middle] < target):
				begin = middle;
				return self.searchrank(nums, target,begin ,end);
			else:
				return middle;
		else:
			if target<nums[end] and target>=nums[begin]:
				return begin;
			elif target >= nums[end]:
				return end;
			else:
				return -1;
	
	def searchrow(self, nums, target, begin, end):
		middle = int((begin+end)/2);
		
		if end-begin>1:
			if(nums[middle] > target):
				end = middle;
				return self.searchrow(nums, target,begin,end);
			elif(nums[middle] < target):
				begin = middle;
				return self.searchrow(nums, target,begin ,end);
			else:
				return True;
		else:
			if nums[begin]==target:
				return True;
			elif nums[end] == target:
				return True;
			else:
				return False;

	def searchMatrix(self, matrix, target):
		ranklist = [];
		if len(matrix) !=0:
			for i in matrix:
				if len(i) != 0:
					ranklist.append(i[0]);
			row = self.searchrank(ranklist,target ,0, len(ranklist)-1 );
		else:
			return False;
		print(row);
		if row != -1 :
			rowlist = matrix[row];
			return self.searchrow(rowlist,target ,0, len(rowlist)-1 );
		else:
			return False;
			
		
so = Solution();

list = [[1,2,8,10,16,21,23,30,31,37,39,43,44,46,53,59,66,68,71],[90,113,125,138,157,182,207,229,242,267,289,308,331,346,370,392,415,429,440],[460,478,494,506,527,549,561,586,609,629,649,665,683,704,729,747,763,786,796],[808,830,844,864,889,906,928,947,962,976,998,1016,1037,1058,1080,1093,1111,1136,1157],[1180,1204,1220,1235,1251,1272,1286,1298,1320,1338,1362,1378,1402,1416,1441,1456,1475,1488,1513],[1533,1548,1563,1586,1609,1634,1656,1667,1681,1706,1731,1746,1760,1778,1794,1815,1830,1846,1861]];
result = so.searchMatrix(list, 1861);
print(result);
		
		
		
		
		
		
		
		
	
	
	
	
	
	