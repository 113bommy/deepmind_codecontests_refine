
px,py = map(int,input().split())
qx,qy = map(int,input().split())
n,s= int(input()),0
for _ in range(n):
	a,b,c = map(int,input().split())
	if not a:
		x,y = 0,-c/b
	else:
		x,y = -c/a,0
	s += ((px-x)*a+(py-y)*b)*((qx-x)*a+(qy-y)*b)<0
print(s)


#  C:\Users\Usuario\HOME2\Programacion\ACM