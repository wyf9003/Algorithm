# 给定一个字符串和一个偏移量，根据偏移量旋转字符串(从左向右旋转)
# 在数组上原地旋转，使用O(1)的额外空间

str = "abcdefghijklmn";
offset = 4;
strlist = list(str);
length = len(str);
i = 0;

if(length != 0):
	realoffset = offset%length;
	while(i<realoffset):
		temp = strlist[length-1];
		j = length-1;
		while(j>0):
			strlist[j] = strlist[j-1];
			j = j-1;
		strlist[0] = temp;
		i = i+1;
	
str=''.join(strlist);
print(str);


