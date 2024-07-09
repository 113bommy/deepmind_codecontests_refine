import sys
input=sys.stdin.readline
n,q=map(int,input().split())
s=input().rstrip()
td=[]
for _ in range(q):
	t,d=input().split()
	td.append((t,d))
l=-1;r=n+1
while r-l>1:#l以上r未満
	mid=(l+r)//2
	now=mid
	if not 0<=now<n:
		if now==-1:
			l=mid
		else:
			r=mid
		continue
	for i in range(q):
		if s[now]==td[i][0]:
			if td[i][1]=="L":
				now-=1
			else:
				now+=1
		if not 0<=now<n:
			f=0
			break
	if now==-1:
		l=mid
	else:
		r=mid
Left=l
l=-2;r=n
while r-l>1:#l over r以下
	mid=(l+r)//2
	now=mid
	if not 0<=now<n:
		if now==n:
			r=mid
		else:
			l=mid
		continue
	for i in range(q):
		if s[now]==td[i][0]:
			if td[i][1]=="L":
				now-=1
			else:
				now+=1
		if not 0<=now<n:
			f=0
			break
	if now==n:
		r=mid
	else:
		l=mid
Right=r#Right,Leftはどこまで排除されるか
print(Right-Left-1)