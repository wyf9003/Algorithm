pointa = 0;
pointb = 0;
pointc = 0;

A = [1,2,5,9];
B = [2,3,4,5,7,8,11,15,30,34];
c = [];

i = 0;

sizea = len(A);
sizeb = len(B);

while (pointa<sizea) and (pointb<sizeb):
	if(A[pointa] <= B[pointb]):
		c.append(A[pointa]);
		pointa = pointa+1;
	else:
		c.append(B[pointb]);
		pointb = pointb+1 ;

if(pointa>=sizea):
	while(pointb<sizeb):
		c.append(B[pointb]);
		pointb = pointb+1;
elif(pointb>=sizeb):
	while(pointa<sizea):
		c.append(A[pointa]);
		pointa = pointa+1;
		
print(c);		
		
		