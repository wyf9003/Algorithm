# 给你一个整数n. 从 1 到 n 按照下面的规则打印每个数：
# 如果这个数被3整除，打印fizz.
# 如果这个数被5整除，打印buzz.
# 如果这个数能同时被3和5整除，打印fizz buzz.
# 只用一个if

def fizzBuzz(n):
	list = [];
	i = 1;

	while(i <= n):
		print(i);
		flag = "";
		while(i%3 == 0):
			flag = "fizz";
			while(i%5 == 0):
				flag = "fizz buzz";
				break;
			break;
		while((i%5 == 0) and(len(flag) != 9)):
			flag = "buzz";
			break;
		while(len(flag) == 0):
			flag = str(i);
			break;
		print(flag);
		list.append(flag);
		i = i+1;
	return list;
	
n  = 20;			
list = fizzBuzz(n);
print(list);




	
	
