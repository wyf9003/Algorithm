# 对于一个给定的 source 字符串和一个 target 字符串
# 应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)
# 如果不存在，则返回 -1

def strStr(self, source, target):
	find = 0;
	si = 0;
	lens = 0;
	lent = 0;
	if source == None or target == None:
		return -1;
	else:
		lens = len(source);
		lent = len(target);
	
	if lent==0 :
		return 0;
	elif lens == 0:
		return -1;
	else:    
		while si < lens :
			if source[si] == target[0]:
				tempsi = si;
				ti = 0;
				while tempsi<lens and source[tempsi] == target[ti]:
					tempsi = tempsi+1;
					ti = ti+1;
					if ti == lent:
						find = 1;
						break;
			if find == 1:
				break;
			else:
				si = si+1;
		if si != lens:
			return si;
		else:
			return -1;
		
source = "null";
target = "a";
n = strStr(source, target);
print(n);


