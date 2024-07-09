n=int(input())
l=[]
for i in range(n):
	r=list(map(int,input().split()))
	l.append(r)
count=0
plus=0

for i in range(n):
	for j in range(n):
		if n<=3:
			count=count+l[i][j]
		else:
			plus=plus+l[i][j]
if n>3:
	for j in range(1,n,2):
		plus=plus-(l[0][j])
		plus=plus-(l[n-1][j])
	for i in range(1,n,2):
		plus=plus-(l[i][0])
		plus=plus-(l[i][n-1])
if n>3:
	print(plus)
if n<=3:
	print(count)