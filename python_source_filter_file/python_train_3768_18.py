t=int(input())
for i in range(t):
	n=int(input())
	a=list(map(int,input().split()))
	if sum(a)%n==0:
		print(sum(a)//4)
	else:
		print(sum(a)//n+1)