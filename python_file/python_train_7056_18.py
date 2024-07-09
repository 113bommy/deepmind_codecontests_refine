s=input()
n=int(input())
f=0
l=""
r=""
for i in range(n):
	q=input().split()
	if q[0]=="1":
		f^=1
	else:
		if (f==0 and q[1]=="1") or (f==1 and q[1]=="2"):
			l=l+q[2]
		else:
			r=r+q[2]

if f==0:
	ans=l[::-1]+s+r
else:
	ans=r[::-1]+s[::-1]+l

print(ans)





