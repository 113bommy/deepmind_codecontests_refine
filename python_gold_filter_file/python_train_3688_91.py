
# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n=int(input())
l=list(map(int,input().split()))
a,b=map(int,input().split())
c=0
for i in range(a-1,b-1):
	c+=l[i]
	
print(c)	