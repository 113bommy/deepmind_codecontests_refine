import sys
input = sys.stdin.readline
n,q=map(int,input().split())
s=input()
Q=[input().rsplit() for _ in range(q)]
l,r=-1,n
while r-l>1:
	c=m=(l+r)//2
	for t,d in Q:
		if s[c]==t:
			c+= 1 if d=="R" else -1
			if c==-1 or c==n:
				break
	if c==-1:l=m
	else:r=m
a=l
l,r=-1,n
while r-l>1:
	c=m=(l+r)//2
	for t,d in Q:
		if s[c]==t:
			c+= 1 if d=="R" else -1
			if c==-1 or c==n:
				break
	if c==n:r=m
	else:l=m
b=r
print(0 if b<=a else b-a-1)