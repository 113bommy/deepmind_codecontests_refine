x,y=map(int,input().strip().split()[:2])
l=[]
for x in range(int(input())):
	x1,y1,v=map(int,input().strip().split()[:3])
	d=((x-x1)**2)+((y-y1)**2)
	d=d**(1/2)
	l.append(d/v)
print(min(l)) 
