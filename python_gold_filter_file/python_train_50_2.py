n,m=map(int,input().split())
l1=[]
for i in range(n):
	l=list(map(int,input().split()))
	for j in range(1,len(l)):
		if l[j] not in l1:
			l1.append(l[j])
if len(l1)==m:
	print('YES')
else:
	print('NO')