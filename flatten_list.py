# 描述
# 给定一个列表，该列表中的每个要素要么是个列表，要么是整数
# 将其变成一个只包含整数的简单列表。

# 样例
# 给定 [1,2,[1,2]]，返回 [1,2,1,2]
# 给定 [4,[3,[2,[1]]]]，返回 [4,3,2,1]

# 挑战
# 请用非递归方法尝试解答这道题。


class Solution(object):
	result = [];
	
	def flatten(self, nestedList):
		if type(nestedList) == type([]):
			for i in nestedList:
				if type(i)==type([]):
					self.flatten(i);
				else:
					self.result.append(i);
		elif type(nestedList) == type(1):
			self.result.append(nestedList);
		
		return self.result;
			
	
list = 10;
solution = Solution();
list = solution.flatten(list);

print(list);